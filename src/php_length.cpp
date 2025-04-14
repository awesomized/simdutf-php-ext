extern "C" {
#include "php.h"
#include "zend_exceptions.h"
#include "zend_smart_str.h"
#include "ext/spl/spl_exceptions.h"
}

#include "src/simdutf.h"
#include "php_length.h"

PHP_FUNCTION(SimdUtf_utf8_length_from_latin1)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    size_t length = simdutf::utf8_length_from_latin1(
        ZSTR_VAL(string),
        ZSTR_LEN(string)
    );

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_latin1_length_from_utf8)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    size_t length = simdutf::latin1_length_from_utf8(
        ZSTR_VAL(string),
        ZSTR_LEN(string)
    );

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_utf16_length_from_utf8)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    size_t length = simdutf::utf16_length_from_utf8(
        ZSTR_VAL(string),
        ZSTR_LEN(string)
    );

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_utf32_length_from_utf8)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    size_t length = simdutf::utf32_length_from_utf8(
        ZSTR_VAL(string),
        ZSTR_LEN(string)
    );

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_latin1_length_from_utf16)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16 string length must be even", 0);
        RETURN_THROWS();
    }

    size_t length = simdutf::latin1_length_from_utf16(ZSTR_LEN(string) / 2);

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_utf8_length_from_utf16)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16 string length must be even", 0);
        RETURN_THROWS();
    }

    size_t length = simdutf::utf8_length_from_utf16(
        reinterpret_cast<const char16_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 2
    );

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_utf8_length_from_utf16le)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16LE string length must be even", 0);
        RETURN_THROWS();
    }

    size_t length = simdutf::utf8_length_from_utf16le(
        reinterpret_cast<const char16_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 2
    );

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_utf8_length_from_utf16be)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16BE string length must be even", 0);
        RETURN_THROWS();
    }

    size_t length = simdutf::utf8_length_from_utf16be(
        reinterpret_cast<const char16_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 2
    );

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_utf8_length_from_utf32)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 4 != 0) {
        zend_throw_exception(NULL, "UTF-32 string length must be a multiple of 4", 0);
        RETURN_THROWS();
    }

    size_t length = simdutf::utf8_length_from_utf32(
        reinterpret_cast<const char32_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 4
    );

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_utf16_length_from_utf32)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 4 != 0) {
        zend_throw_exception(NULL, "UTF-32 string length must be a multiple of 4", 0);
        RETURN_THROWS();
    }

    size_t length = simdutf::utf16_length_from_utf32(
        reinterpret_cast<const char32_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 4
    );

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_utf32_length_from_utf16)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16 string length must be even", 0);
        RETURN_THROWS();
    }

    size_t length = simdutf::utf32_length_from_utf16(
        reinterpret_cast<const char16_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 2
    );

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_utf32_length_from_utf16le)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16LE string length must be even", 0);
        RETURN_THROWS();
    }

    size_t length = simdutf::utf32_length_from_utf16le(
        reinterpret_cast<const char16_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 2
    );

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_utf32_length_from_utf16be)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16BE string length must be even", 0);
        RETURN_THROWS();
    }

    size_t length = simdutf::utf32_length_from_utf16be(
        reinterpret_cast<const char16_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 2
    );

    RETURN_LONG(length);
}

PHP_FUNCTION(SimdUtf_latin1_length_from_utf32)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 4 != 0) {
        zend_throw_exception(NULL, "UTF-32 string length must be a multiple of 4", 0);
        RETURN_THROWS();
    }

    // For UTF-32, each character is one code point and will take one byte in Latin1
    // if it can be represented in Latin1
    RETURN_LONG(ZSTR_LEN(string) / 4);
}

PHP_FUNCTION(SimdUtf_utf16_length_from_latin1)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    // For Latin1, each character will become one UTF-16 character
    // since Latin1 characters are all in the Basic Multilingual Plane
    RETURN_LONG(ZSTR_LEN(string));
}
