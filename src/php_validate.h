#ifndef PHP_SIMDUTF_VALIDATE_H
#define PHP_SIMDUTF_VALIDATE_H

#include "../php_simdutf.h"

BEGIN_EXTERN_C()

PHP_FUNCTION(SimdUtf_validate_utf8);
PHP_FUNCTION(SimdUtf_validate_ascii);
PHP_FUNCTION(SimdUtf_validate_utf16);
PHP_FUNCTION(SimdUtf_validate_utf16le);
PHP_FUNCTION(SimdUtf_validate_utf16be);
PHP_FUNCTION(SimdUtf_validate_utf32);

PHP_FUNCTION(SimdUtf_validate_utf8_with_errors);
PHP_FUNCTION(SimdUtf_validate_ascii_with_errors);
PHP_FUNCTION(SimdUtf_validate_utf16_with_errors);
PHP_FUNCTION(SimdUtf_validate_utf16le_with_errors);
PHP_FUNCTION(SimdUtf_validate_utf16be_with_errors);
PHP_FUNCTION(SimdUtf_validate_utf32_with_errors);

END_EXTERN_C()

#endif
