extern "C" {
#include "php.h"
#include "zend_exceptions.h"
#include "zend_smart_str.h"
#include "ext/spl/spl_exceptions.h"
}

#include "src/simdutf.h"
#include "php_trim.h"

/* Trim partial UTF-8 string */
PHP_FUNCTION(SimdUtf_trim_partial_utf8) {
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len == 0) {
        RETURN_EMPTY_STRING();
    }

    size_t trimmed_len = simdutf::trim_partial_utf8(input, input_len);
    RETURN_STRINGL(input, trimmed_len);
}

/* Trim partial UTF-16BE string */
PHP_FUNCTION(SimdUtf_trim_partial_utf16be) {
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len == 0) {
        RETURN_EMPTY_STRING();
    }

    // Ensure input length is even as UTF-16 uses 2 bytes per unit
    if (input_len % 2 != 0) {
        zend_throw_exception(zend_ce_exception, "Input length must be even for UTF-16BE", 0);
        RETURN_THROWS();
    }

    size_t char16_len = input_len / 2;
    size_t trimmed_units = simdutf::trim_partial_utf16be(
        reinterpret_cast<const char16_t*>(input),
        char16_len
    );

    RETURN_STRINGL(input, trimmed_units * 2);
}

/* Trim partial UTF-16LE string */
PHP_FUNCTION(SimdUtf_trim_partial_utf16le) {
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len == 0) {
        RETURN_EMPTY_STRING();
    }

    // Ensure input length is even as UTF-16 uses 2 bytes per unit
    if (input_len % 2 != 0) {
        zend_throw_exception(zend_ce_exception, "Input length must be even for UTF-16LE", 0);
        RETURN_THROWS();
    }

    size_t char16_len = input_len / 2;
    size_t trimmed_units = simdutf::trim_partial_utf16le(
        reinterpret_cast<const char16_t*>(input),
        char16_len
    );

    RETURN_STRINGL(input, trimmed_units * 2);
}

/* Trim partial UTF-16 string (native endianness) */
PHP_FUNCTION(SimdUtf_trim_partial_utf16) {
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len == 0) {
        RETURN_EMPTY_STRING();
    }

    // Ensure input length is even as UTF-16 uses 2 bytes per unit
    if (input_len % 2 != 0) {
        zend_throw_exception(zend_ce_exception, "Input length must be even for UTF-16", 0);
        RETURN_THROWS();
    }

    size_t char16_len = input_len / 2;
    size_t trimmed_units = simdutf::trim_partial_utf16(
        reinterpret_cast<const char16_t*>(input),
        char16_len
    );

    RETURN_STRINGL(input, trimmed_units * 2);
}
