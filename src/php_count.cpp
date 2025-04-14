extern "C" {
#include "php.h"
#include "zend_exceptions.h"
#include "zend_smart_str.h"
#include "ext/spl/spl_exceptions.h"
}

#include "src/simdutf.h"
#include "php_count.h"

PHP_FUNCTION(SimdUtf_count_utf8) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // Handle empty string case
    if (ZSTR_LEN(string) == 0) {
        RETURN_LONG(0);
    }

    // Validate input pointer
    if (UNEXPECTED(ZSTR_VAL(string) == NULL)) {
        zend_throw_exception(NULL, "Invalid string pointer", 0);
        RETURN_THROWS();
    }

    size_t count = simdutf::count_utf8(ZSTR_VAL(string), ZSTR_LEN(string));
    RETURN_LONG(count);
}

PHP_FUNCTION(SimdUtf_count_utf16) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // Handle empty string case
    if (ZSTR_LEN(string) == 0) {
        RETURN_LONG(0);
    }

    // Convert UTF-8 to UTF-16
    size_t utf16_length = simdutf::utf16_length_from_utf8(
        ZSTR_VAL(string),
        ZSTR_LEN(string)
    );

    char16_t *utf16_input = new char16_t[utf16_length];

    size_t chars_converted = simdutf::convert_utf8_to_utf16(
        ZSTR_VAL(string),
        ZSTR_LEN(string),
        utf16_input
    );

    if (chars_converted != utf16_length) {
        delete[] utf16_input;
        zend_throw_exception(NULL, "Failed to convert input to UTF-16", 0);
        RETURN_THROWS();
    }

    size_t count = simdutf::count_utf16(utf16_input, utf16_length);
    delete[] utf16_input;

    RETURN_LONG(count);
}

PHP_FUNCTION(SimdUtf_count_utf16le) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // Handle empty string case
    if (ZSTR_LEN(string) == 0) {
        RETURN_LONG(0);
    }

    // Convert UTF-8 to UTF-16LE
    size_t utf16_length = simdutf::utf16_length_from_utf8(
        ZSTR_VAL(string),
        ZSTR_LEN(string)
    );

    char16_t *utf16_input = new char16_t[utf16_length];

    size_t chars_converted = simdutf::convert_utf8_to_utf16(
        ZSTR_VAL(string),
        ZSTR_LEN(string),
        utf16_input
    );

    if (chars_converted != utf16_length) {
        delete[] utf16_input;
        zend_throw_exception(NULL, "Failed to convert input to UTF-16LE", 0);
        RETURN_THROWS();
    }

    size_t count = simdutf::count_utf16le(utf16_input, utf16_length);
    delete[] utf16_input;

    RETURN_LONG(count);
}

PHP_FUNCTION(SimdUtf_count_utf16be) {
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // Handle empty string case
    if (ZSTR_LEN(string) == 0) {
        RETURN_LONG(0);
    }

    // Convert UTF-8 to UTF-16BE
    size_t utf16_length = simdutf::utf16_length_from_utf8(
        ZSTR_VAL(string),
        ZSTR_LEN(string)
    );

    char16_t *utf16_input = new char16_t[utf16_length];

    size_t chars_converted = simdutf::convert_utf8_to_utf16(
        ZSTR_VAL(string),
        ZSTR_LEN(string),
        utf16_input
    );

    if (chars_converted != utf16_length) {
        delete[] utf16_input;
        zend_throw_exception(NULL, "Failed to convert input to UTF-16BE", 0);
        RETURN_THROWS();
    }

    size_t count = simdutf::count_utf16be(utf16_input, utf16_length);
    delete[] utf16_input;

    RETURN_LONG(count);
}
