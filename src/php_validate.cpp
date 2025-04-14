extern "C" {
#include "php.h"
#include "zend_exceptions.h"
}

#include "src/simdutf.h"
#include "php_validate.h"

PHP_FUNCTION(SimdUtf_validate_utf8)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    bool is_valid = simdutf::validate_utf8(ZSTR_VAL(string), ZSTR_LEN(string));

    if (is_valid) {
        GC_ADD_FLAGS(string, IS_STR_VALID_UTF8);
    }

    RETURN_BOOL(is_valid);
}

PHP_FUNCTION(SimdUtf_validate_utf8_with_errors)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    simdutf::result result = simdutf::validate_utf8_with_errors(ZSTR_VAL(string), ZSTR_LEN(string));

    array_init(return_value);
    add_assoc_bool(return_value, "valid", !result.error);
    add_assoc_long(return_value, "count", result.count);
    if (result.error) {
        add_assoc_string(return_value, "error", "Invalid UTF-8 sequence");
    }
}

PHP_FUNCTION(SimdUtf_validate_ascii)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    RETURN_BOOL(simdutf::validate_ascii(ZSTR_VAL(string), ZSTR_LEN(string)));
}

PHP_FUNCTION(SimdUtf_validate_ascii_with_errors)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    simdutf::result result = simdutf::validate_ascii_with_errors(ZSTR_VAL(string), ZSTR_LEN(string));

    array_init(return_value);
    add_assoc_bool(return_value, "valid", !result.error);
    add_assoc_long(return_value, "count", result.count);
    if (result.error) {
        add_assoc_string(return_value, "error", "Non-ASCII character found");
    }
}

PHP_FUNCTION(SimdUtf_validate_utf16)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16 string length must be even", 0);
        RETURN_THROWS();
    }

    RETURN_BOOL(simdutf::validate_utf16(
        reinterpret_cast<const char16_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 2
    ));
}

PHP_FUNCTION(SimdUtf_validate_utf16le)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16LE string length must be even", 0);
        RETURN_THROWS();
    }

    RETURN_BOOL(simdutf::validate_utf16le(
        reinterpret_cast<const char16_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 2
    ));
}

PHP_FUNCTION(SimdUtf_validate_utf16be)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16BE string length must be even", 0);
        RETURN_THROWS();
    }

    RETURN_BOOL(simdutf::validate_utf16be(
        reinterpret_cast<const char16_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 2
    ));
}

PHP_FUNCTION(SimdUtf_validate_utf16_with_errors)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16 string length must be even", 0);
        RETURN_THROWS();
    }

    simdutf::result result = simdutf::validate_utf16_with_errors(
        reinterpret_cast<const char16_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 2
    );

    array_init(return_value);
    add_assoc_bool(return_value, "valid", !result.error);
    add_assoc_long(return_value, "count", result.count);
    if (result.error) {
        add_assoc_string(return_value, "error", "Invalid UTF-16 sequence");
    }
}

PHP_FUNCTION(SimdUtf_validate_utf16le_with_errors)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16LE string length must be even", 0);
        RETURN_THROWS();
    }

    simdutf::result result = simdutf::validate_utf16le_with_errors(
        reinterpret_cast<const char16_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 2
    );

    array_init(return_value);
    add_assoc_bool(return_value, "valid", !result.error);
    add_assoc_long(return_value, "count", result.count);
    if (result.error) {
        add_assoc_string(return_value, "error", "Invalid UTF-16LE sequence");
    }
}

PHP_FUNCTION(SimdUtf_validate_utf16be_with_errors)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 2 != 0) {
        zend_throw_exception(NULL, "UTF-16BE string length must be even", 0);
        RETURN_THROWS();
    }

    simdutf::result result = simdutf::validate_utf16be_with_errors(
        reinterpret_cast<const char16_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 2
    );

    array_init(return_value);
    add_assoc_bool(return_value, "valid", !result.error);
    add_assoc_long(return_value, "count", result.count);
    if (result.error) {
        add_assoc_string(return_value, "error", "Invalid UTF-16BE sequence");
    }
}

PHP_FUNCTION(SimdUtf_validate_utf32)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 4 != 0) {
        zend_throw_exception(NULL, "UTF-32 string length must be a multiple of 4", 0);
        RETURN_THROWS();
    }

    bool is_valid = simdutf::validate_utf32(
        reinterpret_cast<const char32_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 4
    );

    RETURN_BOOL(is_valid);
}

PHP_FUNCTION(SimdUtf_validate_utf32_with_errors)
{
    zend_string *string = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    if (ZSTR_LEN(string) % 4 != 0) {
        zend_throw_exception(NULL, "UTF-32 string length must be a multiple of 4", 0);
        RETURN_THROWS();
    }

    simdutf::result result = simdutf::validate_utf32_with_errors(
        reinterpret_cast<const char32_t *>(ZSTR_VAL(string)),
        ZSTR_LEN(string) / 4
    );

    array_init(return_value);
    add_assoc_bool(return_value, "valid", !result.error);
    add_assoc_long(return_value, "count", result.count);
    if (result.error) {
        add_assoc_string(return_value, "error", "Invalid UTF-32 sequence");
    }
}
