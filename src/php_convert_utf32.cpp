extern "C" {
#include "php.h"
#include "zend_exceptions.h"
#include "zend_smart_str.h"
#include "ext/spl/spl_exceptions.h"
}

#include "src/simdutf.h"
#include "php_convert_utf32.h"

/* First, add these function declarations to php_simdutf.h */
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf8);
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16);
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16le);
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16be);
PHP_FUNCTION(SimdUtf_convert_utf32_to_latin1);

/* Implementation in simdutf.c */

/* {{{ proto string simdutf_convert_utf32_to_utf8(string input)
   Convert UTF-32 string to UTF-8 */
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf8)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    // Input length must be a multiple of 4 (size of char32_t)
    if (input_len % sizeof(char32_t) != 0) {
        zend_throw_exception(NULL, "Input length must be a multiple of 4 bytes", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / sizeof(char32_t);
    // UTF-8 can be up to 4 bytes per character
    char *output = (char *)safe_emalloc(char32_len, 4, 1);

    size_t result_len = simdutf::convert_utf32_to_utf8(
        reinterpret_cast<const char32_t *>(input),
        char32_len,
        output
    );

    if (result_len == 0) {
        efree(output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf32_to_utf16(string input)
   Convert UTF-32 string to UTF-16 using native endianness */
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % sizeof(char32_t) != 0) {
        zend_throw_exception(NULL, "Input length must be a multiple of 4 bytes", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / sizeof(char32_t);
    // UTF-16 can use up to 2 code units (4 bytes) per character
    char16_t *output = (char16_t *)safe_emalloc(char32_len, sizeof(char16_t) * 2, 1);

    size_t result_len = simdutf::convert_utf32_to_utf16(
        reinterpret_cast<const char32_t *>(input),
        char32_len,
        output
    );

    if (result_len == 0) {
        efree(output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL((char *)output, result_len * sizeof(char16_t));
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf32_to_utf16le(string input)
   Convert UTF-32 string to UTF-16LE */
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16le)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % sizeof(char32_t) != 0) {
        zend_throw_exception(NULL, "Input length must be a multiple of 4 bytes", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / sizeof(char32_t);
    char16_t *output = (char16_t *)safe_emalloc(char32_len, sizeof(char16_t) * 2, 1);

    size_t result_len = simdutf::convert_utf32_to_utf16le(
        reinterpret_cast<const char32_t *>(input),
        char32_len,
        output
    );

    if (result_len == 0) {
        efree(output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL((char *)output, result_len * sizeof(char16_t));
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf32_to_utf16be(string input)
   Convert UTF-32 string to UTF-16BE */
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16be)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % sizeof(char32_t) != 0) {
        zend_throw_exception(NULL, "Input length must be a multiple of 4 bytes", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / sizeof(char32_t);
    char16_t *output = (char16_t *)safe_emalloc(char32_len, sizeof(char16_t) * 2, 1);

    size_t result_len = simdutf::convert_utf32_to_utf16be(
        reinterpret_cast<const char32_t *>(input),
        char32_len,
        output
    );

    if (result_len == 0) {
        efree(output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL((char *)output, result_len * sizeof(char16_t));
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf32_to_latin1(string input)
   Convert UTF-32 string to Latin1 */
PHP_FUNCTION(SimdUtf_convert_utf32_to_latin1)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % sizeof(char32_t) != 0) {
        zend_throw_exception(NULL, "Input length must be a multiple of 4 bytes", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / sizeof(char32_t);
    char *output = (char *)safe_emalloc(char32_len, 1, 1);

    size_t result_len = simdutf::convert_utf32_to_latin1(
        reinterpret_cast<const char32_t *>(input),
        char32_len,
        output
    );

    if (result_len == 0) {
        efree(output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf32_to_utf8_with_errors(string input)
   Convert UTF-32 string to UTF-8 with error checking */
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf8_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    // Check if input length is multiple of 4 (UTF-32 characters are 4 bytes)
    if (input_len % 4 != 0) {
        zend_throw_exception(NULL, "Input length must be a multiple of 4 bytes", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / 4;
    // UTF-8 can be up to 4 bytes per UTF-32 character
    char *output = (char *)safe_emalloc(char32_len, 4, 1);

    simdutf::result result = simdutf::convert_utf32_to_utf8_with_errors(
        (const char32_t *)input,
        char32_len,
        output
    );

    array_init(return_value);

    if (result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_position", result.count);
        efree(output);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", output, result.count);
        efree(output);
    }
}
/* }}} */

/* {{{ proto array simdutf_convert_utf32_to_latin1_with_errors(string input)
   Convert UTF-32 string to Latin1 with error checking */
PHP_FUNCTION(SimdUtf_convert_utf32_to_latin1_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 4 != 0) {
        zend_throw_exception(NULL, "Input length must be a multiple of 4 bytes", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / 4;
    // Latin1 is one byte per character
    char *output = (char *)safe_emalloc(char32_len, 1, 1);

    simdutf::result result = simdutf::convert_utf32_to_latin1_with_errors(
        (const char32_t *)input,
        char32_len,
        output
    );

    array_init(return_value);

    if (result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_position", result.count);
        efree(output);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", output, result.count);
        efree(output);
    }
}
/* }}} */

/* {{{ proto array simdutf_convert_utf32_to_utf16_with_errors(string input)
   Convert UTF-32 string to UTF-16 with error checking using native endianness */
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 4 != 0) {
        zend_throw_exception(NULL, "Input length must be a multiple of 4 bytes", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / 4;
    // UTF-16 can be up to 2 16-bit units per UTF-32 character
    char16_t *output = (char16_t *)safe_emalloc(char32_len, sizeof(char16_t) * 2, 1);

    simdutf::result result = simdutf::convert_utf32_to_utf16_with_errors(
        (const char32_t *)input,
        char32_len,
        output
    );

    array_init(return_value);

    if (result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_position", result.count);
        efree(output);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", (char *)output, result.count * sizeof(char16_t));
        efree(output);
    }
}
/* }}} */

/* {{{ proto array simdutf_convert_utf32_to_utf16le_with_errors(string input)
   Convert UTF-32 string to UTF-16LE with error checking */
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16le_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 4 != 0) {
        zend_throw_exception(NULL, "Input length must be a multiple of 4 bytes", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / 4;
    char16_t *output = (char16_t *)safe_emalloc(char32_len, sizeof(char16_t) * 2, 1);

    simdutf::result result = simdutf::convert_utf32_to_utf16le_with_errors(
        (const char32_t *)input,
        char32_len,
        output
    );

    array_init(return_value);

    if (result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_position", result.count);
        efree(output);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", (char *)output, result.count * sizeof(char16_t));
        efree(output);
    }
}
/* }}} */

/* {{{ proto array simdutf_convert_utf32_to_utf16be_with_errors(string input)
   Convert UTF-32 string to UTF-16BE with error checking */
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16be_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 4 != 0) {
        zend_throw_exception(NULL, "Input length must be a multiple of 4 bytes", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / 4;
    char16_t *output = (char16_t *)safe_emalloc(char32_len, sizeof(char16_t) * 2, 1);

    simdutf::result result = simdutf::convert_utf32_to_utf16be_with_errors(
        (const char32_t *)input,
        char32_len,
        output
    );

    array_init(return_value);

    if (result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_position", result.count);
        efree(output);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", (char *)output, result.count * sizeof(char16_t));
        efree(output);
    }
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf32_to_latin1(string input)
   Convert valid UTF-32 string to Latin1. Expert use only - assumes valid UTF-32 input. */
PHP_FUNCTION(SimdUtf_convert_valid_utf32_to_latin1)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    // Input length must be multiple of 4 (size of char32_t)
    if (input_len % 4 != 0) {
        zend_throw_exception(NULL, "Invalid UTF-32 string length", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / 4;
    // Output buffer will be same length as number of UTF-32 characters
    char *output = (char *)safe_emalloc(char32_len, 1, 1);

    size_t result_len = simdutf::convert_valid_utf32_to_latin1(
        reinterpret_cast<const char32_t *>(input),
        char32_len,
        output
    );

    if (result_len == 0) {
        efree(output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf32_to_utf8(string input)
   Convert valid UTF-32 string to UTF-8. Assumes valid UTF-32 input. */
PHP_FUNCTION(SimdUtf_convert_valid_utf32_to_utf8)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 4 != 0) {
        zend_throw_exception(NULL, "Invalid UTF-32 string length", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / 4;
    // Allocate for worst case: 4 bytes per character in UTF-8
    char *output = (char *)safe_emalloc(char32_len, 4, 1);

    size_t result_len = simdutf::convert_valid_utf32_to_utf8(
        reinterpret_cast<const char32_t *>(input),
        char32_len,
        output
    );

    if (result_len == 0) {
        efree(output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf32_to_utf16le(string input)
   Convert valid UTF-32 string to UTF-16LE. Assumes valid UTF-32 input. */
PHP_FUNCTION(SimdUtf_convert_valid_utf32_to_utf16le)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 4 != 0) {
        zend_throw_exception(NULL, "Invalid UTF-32 string length", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / 4;
    // Allocate for worst case: 2 UTF-16 units per UTF-32 character
    char16_t *output = (char16_t *)safe_emalloc(char32_len, 2 * sizeof(char16_t), 1);

    size_t result_len = simdutf::convert_valid_utf32_to_utf16le(
        reinterpret_cast<const char32_t *>(input),
        char32_len,
        output
    );

    if (result_len == 0) {
        efree(output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL((char *)output, result_len * sizeof(char16_t));
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf32_to_utf16be(string input)
   Convert valid UTF-32 string to UTF-16BE. Assumes valid UTF-32 input. */
PHP_FUNCTION(SimdUtf_convert_valid_utf32_to_utf16be)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 4 != 0) {
        zend_throw_exception(NULL, "Invalid UTF-32 string length", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / 4;
    // Allocate for worst case: 2 UTF-16 units per UTF-32 character
    char16_t *output = (char16_t *)safe_emalloc(char32_len, 2 * sizeof(char16_t), 1);

    size_t result_len = simdutf::convert_valid_utf32_to_utf16be(
        reinterpret_cast<const char32_t *>(input),
        char32_len,
        output
    );

    if (result_len == 0) {
        efree(output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL((char *)output, result_len * sizeof(char16_t));
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf32_to_utf16(string input)
   Convert valid UTF-32 string to UTF-16 using native endianness. Assumes valid UTF-32 input. */
PHP_FUNCTION(SimdUtf_convert_valid_utf32_to_utf16)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    // Input length must be multiple of 4 (size of char32_t)
    if (input_len % 4 != 0) {
        zend_throw_exception(NULL, "Invalid UTF-32 string length", 0);
        RETURN_FALSE;
    }

    size_t char32_len = input_len / 4;
    // Allocate for worst case: 2 UTF-16 units per UTF-32 character
    char16_t *output = (char16_t *)safe_emalloc(char32_len, 2 * sizeof(char16_t), 1);

    size_t result_len = simdutf::convert_valid_utf32_to_utf16(
        reinterpret_cast<const char32_t *>(input),
        char32_len,
        output
    );

    if (result_len == 0) {
        efree(output);
        RETURN_FALSE;
    }

    RETVAL_STRINGL((char *)output, result_len * sizeof(char16_t));
    efree(output);
}
/* }}} */
