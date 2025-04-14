extern "C" {
#include "php.h"
#include "zend_exceptions.h"
#include "zend_smart_str.h"
#include "ext/spl/spl_exceptions.h"
}

#include "src/simdutf.h"
#include "php_encoding.h"

/* {{{ proto int simdutf_autodetect_encoding(string input)
   Autodetect the encoding of the input string */
PHP_FUNCTION(SimdUtf_autodetect_encoding)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len == 0) {
        RETURN_LONG(0); // Maps to unspecified
    }

    // Return the raw enum value - it matches the intended constants
    RETURN_LONG((zend_long)simdutf::autodetect_encoding(input, input_len));
}
/* }}} */

/* {{{ proto int simdutf_detect_encodings(string input)
   Detect all possible encodings of the input string */
PHP_FUNCTION(SimdUtf_detect_encodings)
{
    char *input;
    size_t input_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(input, input_len)
    ZEND_PARSE_PARAMETERS_END();

    if (input_len == 0) {
        RETURN_LONG(0); // Return 0 for empty input
    }

    int result = simdutf::detect_encodings(input, input_len);

    // Return the raw bitmask of detected encodings
    RETURN_LONG((zend_long)result);
}
/* }}} */
