extern "C" {
#include "php.h"
#include "zend_exceptions.h"
#include "zend_smart_str.h"
#include "ext/spl/spl_exceptions.h"
}

#include "src/simdutf.h"
#include "php_base64.h"

PHP_FUNCTION(SimdUtf_binary_to_base64) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // Check for input length overflow - base64 encoding expands by 4/3
    if (ZSTR_LEN(string) > SIZE_MAX * 3 / 4) {
        zend_throw_exception(NULL, "Input string too long", 0);
        RETURN_THROWS();
    }

    size_t encoded_length = simdutf::base64_length_from_binary(ZSTR_LEN(string));

    // Double check the encoded length is what we expect
    if (encoded_length == 0 && ZSTR_LEN(string) != 0) {
        zend_throw_exception(NULL, "Failed to calculate base64 length", 0);
        RETURN_THROWS();
    }

    zend_string *result = zend_string_alloc(encoded_length, 0);
    if (!result) {
        zend_throw_exception(NULL, "Failed to allocate memory", 0);
        RETURN_THROWS();
    }

    size_t written = simdutf::binary_to_base64(
        ZSTR_VAL(string),
        ZSTR_LEN(string),
        ZSTR_VAL(result)
    );

    // Sanity check on written bytes
    if (written != encoded_length) {
        zend_string_free(result);
        zend_throw_exception(NULL, "Unexpected number of bytes written during base64 encoding", 0);
        RETURN_THROWS();
    }

    GC_ADD_FLAGS(result, IS_STR_VALID_UTF8); // base64 encoded string must be always valid UTF-8 string

    RETURN_STR(result);
}

PHP_FUNCTION(SimdUtf_base64_to_binary) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // For base64, every 4 chars encode 3 bytes
    size_t decoded_length = (ZSTR_LEN(string) * 3) / 4;
    zend_string *result = zend_string_alloc(decoded_length, 0);

    simdutf::result decode_result = simdutf::base64_to_binary(
        ZSTR_VAL(string),
        ZSTR_LEN(string),
        ZSTR_VAL(result)
    );

    if (decode_result.error) {
        zend_string_free(result);
        if (decode_result.error == simdutf::error_code::INVALID_BASE64_CHARACTER) {
            char error_message[128];
            snprintf(error_message, sizeof(error_message),
                    "Invalid base64 character at position %zu", decode_result.count);
            zend_throw_exception(NULL, error_message, 0);
        } else if (decode_result.error == simdutf::error_code::BASE64_INPUT_REMAINDER) {
            zend_throw_exception(NULL, "Invalid base64 input length", 0);
        } else {
            zend_throw_exception(NULL, "Base64 decoding failed", 0);
        }
        RETURN_THROWS();
    }

    // Resize the result to the actual number of bytes written
    if (decode_result.count < decoded_length) {
        result = zend_string_truncate(result, decode_result.count, 0);
    }

    RETURN_STR(result);
}

PHP_FUNCTION(SimdUtf_base64_to_binary_safe) {
    zend_string *input_str = NULL;
    zend_long max_output_length = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STR(input_str)
        Z_PARAM_LONG(max_output_length)
    ZEND_PARSE_PARAMETERS_END();

    // Validate max output length
    if (max_output_length < 0) {
        zend_throw_exception(NULL, "Maximum output length cannot be negative", 0);
        RETURN_THROWS();
    }

    // For base64, every 4 chars encode 3 bytes, calculate maximum possible decoded length
    size_t potential_decoded_length = (ZSTR_LEN(input_str) * 3) / 4;

    // Use the smaller of max_output_length or potential_decoded_length
    size_t output_buffer_size = (size_t)max_output_length;
    if (potential_decoded_length < output_buffer_size) {
        output_buffer_size = potential_decoded_length;
    }

    // Allocate output buffer with the calculated size
    zend_string *result = zend_string_alloc(output_buffer_size, 0);
    if (!result) {
        zend_throw_exception(NULL, "Failed to allocate memory for output buffer", 0);
        RETURN_THROWS();
    }

    // Prepare outlen parameter for simdutf::base64_to_binary_safe
    size_t actual_output_length = output_buffer_size;

    // Perform the safe base64 decoding
    simdutf::result decode_result = simdutf::base64_to_binary_safe(
        ZSTR_VAL(input_str),
        ZSTR_LEN(input_str),
        ZSTR_VAL(result),
        actual_output_length,
        simdutf::base64_default,
        simdutf::last_chunk_handling_options::loose
    );

    // Handle potential errors
    if (decode_result.error) {
        zend_string_free(result);

        switch (decode_result.error) {
            case simdutf::error_code::INVALID_BASE64_CHARACTER:
                {
                    char error_message[128];
                    snprintf(error_message, sizeof(error_message),
                            "Invalid base64 character at position %zu", decode_result.count);
                    zend_throw_exception(NULL, error_message, 0);
                }
                break;

            case simdutf::error_code::BASE64_INPUT_REMAINDER:
                zend_throw_exception(NULL, "Invalid base64 input length", 0);
                break;

            case simdutf::error_code::OUTPUT_BUFFER_TOO_SMALL:
                {
                    char error_message[128];
                    snprintf(error_message, sizeof(error_message),
                            "Output buffer too small. Required size: %zu", decode_result.count);
                    zend_throw_exception(NULL, error_message, 0);
                }
                break;

            default:
                zend_throw_exception(NULL, "Base64 decoding failed", 0);
        }

        RETURN_THROWS();
    }

    // Resize the result string to match the actual number of bytes written
    if (actual_output_length < output_buffer_size) {
        result = zend_string_truncate(result, actual_output_length, 0);
    }

    RETURN_STR(result);
}
