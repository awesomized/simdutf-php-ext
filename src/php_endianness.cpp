extern "C" {
#include "php.h"
#include "zend_exceptions.h"
#include "zend_smart_str.h"
#include "ext/spl/spl_exceptions.h"
}

#include "src/simdutf.h"
#include "php_endianness.h"

/* {{{ proto string simdutf_change_endianness_utf16(string input)
   Change the endianness of a UTF-16 string (LE to BE or BE to LE) */
PHP_FUNCTION(SimdUtf_change_endianness_utf16)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    // Check if input length is valid (must be even for UTF-16)
    if (input_len % 2 != 0) {
        zend_throw_exception(NULL, "Input length must be even (UTF-16 requires 2 bytes per code unit)", 0);
        RETURN_FALSE;
    }

    // Calculate length in char16_t units
    size_t char16_len = input_len / 2;

    // Allocate output buffer (same size as input)
    char16_t *output = (char16_t *)safe_emalloc(char16_len, sizeof(char16_t), 1);

    // Call the simdutf function
    simdutf::change_endianness_utf16(
        reinterpret_cast<const char16_t *>(input),
        char16_len,
        output
    );

    // Return the converted string
    RETVAL_STRINGL((char *)output, input_len);
    efree(output);
}
/* }}} */
