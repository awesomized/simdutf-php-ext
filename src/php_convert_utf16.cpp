extern "C" {
#include "php.h"
#include "zend_exceptions.h"
#include "zend_smart_str.h"
#include "ext/spl/spl_exceptions.h"
}

#include "src/simdutf.h"
#include "php_convert_utf16.h"

/* {{{ proto string simdutf_convert_utf16_to_utf8(string input)
   Convert UTF-16 string to UTF-8 using native endianness */
PHP_FUNCTION(SimdUtf_convert_utf16_to_utf8)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 3, 1);

    size_t result_len = simdutf::convert_utf16_to_utf8(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf16le_to_utf8(string input)
   Convert UTF-16LE string to UTF-8 */
PHP_FUNCTION(SimdUtf_convert_utf16le_to_utf8)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16LE", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 3, 1);

    size_t result_len = simdutf::convert_utf16le_to_utf8(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf16be_to_utf8(string input)
   Convert UTF-16BE string to UTF-8 */
PHP_FUNCTION(SimdUtf_convert_utf16be_to_utf8)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16BE", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 3, 1);

    size_t result_len = simdutf::convert_utf16be_to_utf8(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf16_to_latin1(string input)
   Convert UTF-16 string to Latin1 using native endianness */
PHP_FUNCTION(SimdUtf_convert_utf16_to_latin1)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 1, 1);

    size_t result_len = simdutf::convert_utf16_to_latin1(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf16le_to_latin1(string input)
   Convert UTF-16LE string to Latin1 */
PHP_FUNCTION(SimdUtf_convert_utf16le_to_latin1)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16LE", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 1, 1);

    size_t result_len = simdutf::convert_utf16le_to_latin1(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf16be_to_latin1(string input)
   Convert UTF-16BE string to Latin1 */
PHP_FUNCTION(SimdUtf_convert_utf16be_to_latin1)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16BE", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 1, 1);

    size_t result_len = simdutf::convert_utf16be_to_latin1(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf16_to_utf32(string input)
   Convert UTF-16 string to UTF-32 using native endianness */
PHP_FUNCTION(SimdUtf_convert_utf16_to_utf32)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16", 0);
        return;
    }

    char32_t *output = (char32_t *)safe_emalloc(input_len / 2, sizeof(char32_t), 1);

    size_t result_len = simdutf::convert_utf16_to_utf32(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL((char *)output, result_len * sizeof(char32_t));
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf16le_to_utf32(string input)
   Convert UTF-16LE string to UTF-32 */
PHP_FUNCTION(SimdUtf_convert_utf16le_to_utf32)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16LE", 0);
        return;
    }

    char32_t *output = (char32_t *)safe_emalloc(input_len / 2, sizeof(char32_t), 1);

    size_t result_len = simdutf::convert_utf16le_to_utf32(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL((char *)output, result_len * sizeof(char32_t));
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_utf16be_to_utf32(string input)
   Convert UTF-16BE string to UTF-32 */
PHP_FUNCTION(SimdUtf_convert_utf16be_to_utf32)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16BE", 0);
        return;
    }

    char32_t *output = (char32_t *)safe_emalloc(input_len / 2, sizeof(char32_t), 1);

    size_t result_len = simdutf::convert_utf16be_to_utf32(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL((char *)output, result_len * sizeof(char32_t));
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf16_to_utf8(string input)
   Convert valid UTF-16 string to UTF-8 using native endianness */
PHP_FUNCTION(SimdUtf_convert_valid_utf16_to_utf8)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 3, 1);

    size_t result_len = simdutf::convert_valid_utf16_to_utf8(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf16le_to_utf8(string input)
   Convert valid UTF-16LE string to UTF-8 */
PHP_FUNCTION(SimdUtf_convert_valid_utf16le_to_utf8)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16LE", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 3, 1);

    size_t result_len = simdutf::convert_valid_utf16le_to_utf8(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf16be_to_utf8(string input)
   Convert valid UTF-16BE string to UTF-8 */
PHP_FUNCTION(SimdUtf_convert_valid_utf16be_to_utf8)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16BE", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 3, 1);

    size_t result_len = simdutf::convert_valid_utf16be_to_utf8(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf16_to_latin1(string input)
   Convert valid UTF-16 string to Latin1 using native endianness */
PHP_FUNCTION(SimdUtf_convert_valid_utf16_to_latin1)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 1, 1);

    size_t result_len = simdutf::convert_valid_utf16_to_latin1(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf16le_to_latin1(string input)
   Convert valid UTF-16LE string to Latin1 */
PHP_FUNCTION(SimdUtf_convert_valid_utf16le_to_latin1)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16LE", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 1, 1);

    size_t result_len = simdutf::convert_valid_utf16le_to_latin1(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf16be_to_latin1(string input)
   Convert valid UTF-16BE string to Latin1 */
PHP_FUNCTION(SimdUtf_convert_valid_utf16be_to_latin1)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16BE", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 1, 1);

    size_t result_len = simdutf::convert_valid_utf16be_to_latin1(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL(output, result_len);
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf16_to_utf32(string input)
   Convert valid UTF-16 string to UTF-32 using native endianness */
PHP_FUNCTION(SimdUtf_convert_valid_utf16_to_utf32)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16", 0);
        return;
    }

    char32_t *output = (char32_t *)safe_emalloc(input_len / 2, sizeof(char32_t), 1);

    size_t result_len = simdutf::convert_valid_utf16_to_utf32(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL((char *)output, result_len * sizeof(char32_t));
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf16le_to_utf32(string input)
   Convert valid UTF-16LE string to UTF-32 */
PHP_FUNCTION(SimdUtf_convert_valid_utf16le_to_utf32)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16LE", 0);
        return;
    }

    char32_t *output = (char32_t *)safe_emalloc(input_len / 2, sizeof(char32_t), 1);

    size_t result_len = simdutf::convert_valid_utf16le_to_utf32(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL((char *)output, result_len * sizeof(char32_t));
    efree(output);
}
/* }}} */

/* {{{ proto string simdutf_convert_valid_utf16be_to_utf32(string input)
   Convert valid UTF-16BE string to UTF-32 */
PHP_FUNCTION(SimdUtf_convert_valid_utf16be_to_utf32)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16BE", 0);
        return;
    }

    char32_t *output = (char32_t *)safe_emalloc(input_len / 2, sizeof(char32_t), 1);

    size_t result_len = simdutf::convert_valid_utf16be_to_utf32(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    RETVAL_STRINGL((char *)output, result_len * sizeof(char32_t));
    efree(output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf16_to_utf8_with_errors(string input)
   Convert UTF-16 string to UTF-8 with error reporting */
PHP_FUNCTION(SimdUtf_convert_utf16_to_utf8_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 3, 1);

    simdutf::result conv_result = simdutf::convert_utf16_to_utf8_with_errors(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    array_init(return_value);
    if (conv_result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", conv_result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", output, conv_result.count);
    }
    efree(output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf16le_to_utf8_with_errors(string input)
   Convert UTF-16LE string to UTF-8 with error reporting */
PHP_FUNCTION(SimdUtf_convert_utf16le_to_utf8_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16LE", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 3, 1);

    simdutf::result conv_result = simdutf::convert_utf16le_to_utf8_with_errors(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    array_init(return_value);
    if (conv_result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", conv_result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", output, conv_result.count);
    }
    efree(output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf16be_to_utf8_with_errors(string input)
   Convert UTF-16BE string to UTF-8 with error reporting */
PHP_FUNCTION(SimdUtf_convert_utf16be_to_utf8_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16BE", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 3, 1);

    simdutf::result conv_result = simdutf::convert_utf16be_to_utf8_with_errors(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    array_init(return_value);
    if (conv_result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", conv_result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", output, conv_result.count);
    }
    efree(output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf16_to_latin1_with_errors(string input)
   Convert UTF-16 string to Latin1 with error reporting */
PHP_FUNCTION(SimdUtf_convert_utf16_to_latin1_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 1, 1);

    simdutf::result conv_result = simdutf::convert_utf16_to_latin1_with_errors(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    array_init(return_value);
    if (conv_result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", conv_result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", output, conv_result.count);
    }
    efree(output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf16le_to_latin1_with_errors(string input)
   Convert UTF-16LE string to Latin1 with error reporting */
PHP_FUNCTION(SimdUtf_convert_utf16le_to_latin1_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16LE", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 1, 1);

    simdutf::result conv_result = simdutf::convert_utf16le_to_latin1_with_errors(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    array_init(return_value);
    if (conv_result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", conv_result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", output, conv_result.count);
    }
    efree(output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf16be_to_latin1_with_errors(string input)
   Convert UTF-16BE string to Latin1 with error reporting */
PHP_FUNCTION(SimdUtf_convert_utf16be_to_latin1_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16BE", 0);
        return;
    }

    char *output = (char *)safe_emalloc(input_len / 2, 1, 1);

    simdutf::result conv_result = simdutf::convert_utf16be_to_latin1_with_errors(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    array_init(return_value);
    if (conv_result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", conv_result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", output, conv_result.count);
    }
    efree(output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf16_to_utf32_with_errors(string input)
   Convert UTF-16 string to UTF-32 with error reporting */
PHP_FUNCTION(SimdUtf_convert_utf16_to_utf32_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16", 0);
        return;
    }

    char32_t *output = (char32_t *)safe_emalloc(input_len / 2, sizeof(char32_t), 1);

    simdutf::result conv_result = simdutf::convert_utf16_to_utf32_with_errors(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    array_init(return_value);
    if (conv_result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", conv_result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", (char *)output, conv_result.count * sizeof(char32_t));
    }
    efree(output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf16le_to_utf32_with_errors(string input)
   Convert UTF-16LE string to UTF-32 with error reporting */
PHP_FUNCTION(SimdUtf_convert_utf16le_to_utf32_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16LE", 0);
        return;
    }

    char32_t *output = (char32_t *)safe_emalloc(input_len / 2, sizeof(char32_t), 1);

    simdutf::result conv_result = simdutf::convert_utf16le_to_utf32_with_errors(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    array_init(return_value);
    if (conv_result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", conv_result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", (char *)output, conv_result.count * sizeof(char32_t));
    }
    efree(output);
}
/* }}} */

/* {{{ proto array simdutf_convert_utf16be_to_utf32_with_errors(string input)
   Convert UTF-16BE string to UTF-32 with error reporting */
PHP_FUNCTION(SimdUtf_convert_utf16be_to_utf32_with_errors)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even for UTF-16BE", 0);
        return;
    }

    char32_t *output = (char32_t *)safe_emalloc(input_len / 2, sizeof(char32_t), 1);

    simdutf::result conv_result = simdutf::convert_utf16be_to_utf32_with_errors(
        (const char16_t *)input,
        input_len / 2,
        output
    );

    array_init(return_value);
    if (conv_result.error) {
        add_assoc_bool(return_value, "success", 0);
        add_assoc_long(return_value, "error_offset", conv_result.count);
    } else {
        add_assoc_bool(return_value, "success", 1);
        add_assoc_stringl(return_value, "output", (char *)output, conv_result.count * sizeof(char32_t));
    }
    efree(output);
}
/* }}} */
