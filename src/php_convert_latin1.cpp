extern "C" {
#include "php.h"
#include "zend_exceptions.h"
#include "zend_smart_str.h"
#include "ext/spl/spl_exceptions.h"
}

#include "src/simdutf.h"
#include "php_convert_latin1.h"
/* {{{ proto string simdutf_convert_latin1_to_utf8(string input)
   Convert Latin1 string to UTF-8 using simdutf */
PHP_FUNCTION(SimdUtf_convert_latin1_to_utf8)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    // Get required size for UTF-8 output (worst case: input_len * 2)
    size_t utf8_output_capacity = input_len * 2;
    char *utf8_output = (char *)safe_emalloc(utf8_output_capacity, 1, 1);

    // Convert using simdutf - all Latin1 values (0x00-0xFF) are valid
    size_t utf8_output_size = simdutf::convert_latin1_to_utf8(
        reinterpret_cast<const char *>(input),
        input_len,
        reinterpret_cast<char *>(utf8_output)
    );

    RETVAL_STRINGL(utf8_output, utf8_output_size);
    efree(utf8_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_latin1_to_utf16le(string input)
   Convert Latin1 string to UTF-16LE using simdutf */
PHP_FUNCTION(SimdUtf_convert_latin1_to_utf16le)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    // Allocate buffer for UTF-16 output (each Latin1 char becomes one UTF-16 char)
    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    size_t utf16_output_size = simdutf::convert_latin1_to_utf16le(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    RETVAL_STRINGL((char *)utf16_output, utf16_output_size * sizeof(char16_t));
    efree(utf16_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_latin1_to_utf16be(string input)
   Convert Latin1 string to UTF-16BE using simdutf */
PHP_FUNCTION(SimdUtf_convert_latin1_to_utf16be)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char16_t *utf16_output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    size_t utf16_output_size = simdutf::convert_latin1_to_utf16be(
        reinterpret_cast<const char *>(input),
        input_len,
        utf16_output
    );

    RETVAL_STRINGL((char *)utf16_output, utf16_output_size * sizeof(char16_t));
    efree(utf16_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_latin1_to_utf32(string input)
   Convert Latin1 string to UTF-32 using simdutf */
PHP_FUNCTION(SimdUtf_convert_latin1_to_utf32)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    char32_t *utf32_output = (char32_t *)safe_emalloc(input_len, sizeof(char32_t), 1);

    size_t utf32_output_size = simdutf::convert_latin1_to_utf32(
        reinterpret_cast<const char *>(input),
        input_len,
        utf32_output
    );

    RETVAL_STRINGL((char *)utf32_output, utf32_output_size * sizeof(char32_t));
    efree(utf32_output);
}
/* }}} */

/* {{{ proto string simdutf_convert_latin1_to_utf16(string input)
   Convert Latin1 string to UTF-16 using native endianness */
PHP_FUNCTION(SimdUtf_convert_latin1_to_utf16)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    // Allocate output buffer - each input byte becomes one UTF-16 code unit
    char16_t *output = (char16_t *)safe_emalloc(input_len, sizeof(char16_t), 1);

    size_t result_len = simdutf::convert_latin1_to_utf16(input, input_len, output);

    RETVAL_STRINGL((char *)output, result_len * sizeof(char16_t));
    efree(output);
}
/* }}} */
