extern "C" {
#include "php.h"
#include "zend_exceptions.h"
#include "zend_smart_str.h"
#include "ext/spl/spl_exceptions.h"
}

#include "src/simdutf.h"
#include "php_convert_utf8.h"

/* {{{ proto string simdutf_convert_utf8_to_latin1(string input)
   Convert UTF-8 string to Latin1 using simdutf */
PHP_FUNCTION(SimdUtf_convert_utf8_to_latin1)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char *latin1_output = (char *)safe_emalloc(input_len, 1, 1);

    size_t written = simdutf::convert_utf8_to_latin1(
        reinterpret_cast<const char *>(input),
        input_len,
        latin1_output
    );

    RETVAL_STRINGL(latin1_output, written);
    efree(latin1_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf8_to_utf16(string input)
   Convert UTF-8 string to UTF-16 using simdutf */
PHP_FUNCTION(SimdUtf_convert_utf8_to_utf16)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    size_t written = simdutf::convert_utf8_to_utf16(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    RETVAL_STRINGL((char *)utf16_output, written * sizeof(char16_t));
    efree(utf16_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf8_to_utf16le(string input)
   Convert UTF-8 string to UTF-16LE using simdutf */
PHP_FUNCTION(SimdUtf_convert_utf8_to_utf16le)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    size_t written = simdutf::convert_utf8_to_utf16le(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    RETVAL_STRINGL((char *)utf16_output, written * sizeof(char16_t));
    efree(utf16_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf8_to_utf16be(string input)
   Convert UTF-8 string to UTF-16BE using simdutf */
PHP_FUNCTION(SimdUtf_convert_utf8_to_utf16be)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    size_t written = simdutf::convert_utf8_to_utf16be(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    RETVAL_STRINGL((char *)utf16_output, written * sizeof(char16_t));
    efree(utf16_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf8_to_utf32(string input)
   Convert UTF-8 string to UTF-32 using simdutf */
PHP_FUNCTION(SimdUtf_convert_utf8_to_utf32)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char32_t *utf32_output = (char32_t *)safe_emalloc(input_len, sizeof(char32_t), 1);

    size_t written = simdutf::convert_utf8_to_utf32(
        reinterpret_cast<const char *>(input),
        input_len,
        utf32_output
    );

    RETVAL_STRINGL((char *)utf32_output, written * sizeof(char32_t));
    efree(utf32_output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf8_to_latin1_with_errors(string input)
   Convert UTF-8 string to Latin1 with error information */
PHP_FUNCTION(SimdUtf_convert_utf8_to_latin1_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char *latin1_output = (char *)safe_emalloc(input_len, 1, 1);

    simdutf::result result = simdutf::convert_utf8_to_latin1_with_errors(
        reinterpret_cast<const char *>(input),
        input_len,
        latin1_output
    );

    array_init(return_value);

    if (result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", latin1_output, result.count);
    }

    efree(latin1_output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf8_to_utf16_with_errors(string input)
   Convert UTF-8 string to UTF-16 with error information */
PHP_FUNCTION(SimdUtf_convert_utf8_to_utf16_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    simdutf::result result = simdutf::convert_utf8_to_utf16_with_errors(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    array_init(return_value);

    if (result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", (char *)utf16_output, result.count * sizeof(char16_t));
    }

    efree(utf16_output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf8_to_utf16le_with_errors(string input)
   Convert UTF-8 string to UTF-16LE with error information */
PHP_FUNCTION(SimdUtf_convert_utf8_to_utf16le_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    simdutf::result result = simdutf::convert_utf8_to_utf16le_with_errors(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    array_init(return_value);

    if (result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", (char *)utf16_output, result.count * sizeof(char16_t));
    }

    efree(utf16_output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf8_to_utf16be_with_errors(string input)
   Convert UTF-8 string to UTF-16BE with error information */
PHP_FUNCTION(SimdUtf_convert_utf8_to_utf16be_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    simdutf::result result = simdutf::convert_utf8_to_utf16be_with_errors(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    array_init(return_value);

    if (result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", (char *)utf16_output, result.count * sizeof(char16_t));
    }

    efree(utf16_output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf8_to_utf32_with_errors(string input)
   Convert UTF-8 string to UTF-32 with error information */
PHP_FUNCTION(SimdUtf_convert_utf8_to_utf32_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char32_t *utf32_output = (char32_t *)safe_emalloc(input_len, sizeof(char32_t), 1);

    simdutf::result result = simdutf::convert_utf8_to_utf32_with_errors(
        reinterpret_cast<const char *>(input),
        input_len,
        utf32_output
    );

    array_init(return_value);

    if (result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", (char *)utf32_output, result.count * sizeof(char32_t));
    }

    efree(utf32_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf8_to_latin1(string input)
   Convert valid UTF-8 string to Latin1 (no validation) */
PHP_FUNCTION(SimdUtf_convert_valid_utf8_to_latin1)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char *latin1_output = (char *)safe_emalloc(input_len, 1, 1);

    size_t written = simdutf::convert_valid_utf8_to_latin1(
        reinterpret_cast<const char *>(input),
        input_len,
        latin1_output
    );

    RETVAL_STRINGL(latin1_output, written);
    efree(latin1_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf8_to_utf16(string input)
   Convert valid UTF-8 string to UTF-16 (no validation) */
PHP_FUNCTION(SimdUtf_convert_valid_utf8_to_utf16)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    size_t written = simdutf::convert_valid_utf8_to_utf16(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    RETVAL_STRINGL((char *)utf16_output, written * sizeof(char16_t));
    efree(utf16_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf8_to_utf16le(string input)
   Convert valid UTF-8 string to UTF-16LE (no validation) */
PHP_FUNCTION(SimdUtf_convert_valid_utf8_to_utf16le)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    size_t written = simdutf::convert_valid_utf8_to_utf16le(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    RETVAL_STRINGL((char *)utf16_output, written * sizeof(char16_t));
    efree(utf16_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf8_to_utf16be(string input)
   Convert valid UTF-8 string to UTF-16BE (no validation) */
PHP_FUNCTION(SimdUtf_convert_valid_utf8_to_utf16be)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    size_t written = simdutf::convert_valid_utf8_to_utf16be(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    RETVAL_STRINGL((char *)utf16_output, written * sizeof(char16_t));
    efree(utf16_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf8_to_utf32(string input)
   Convert valid UTF-8 string to UTF-32 (no validation) */
PHP_FUNCTION(SimdUtf_convert_valid_utf8_to_utf32)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char32_t *utf32_output = (char32_t *)safe_emalloc(input_len, sizeof(char32_t), 1);

    size_t written = simdutf::convert_valid_utf8_to_utf32(
        reinterpret_cast<const char *>(input),
        input_len,
        utf32_output
    );

    RETVAL_STRINGL((char *)utf32_output, written * sizeof(char32_t));
    efree(utf32_output);
}
/* }}} */
