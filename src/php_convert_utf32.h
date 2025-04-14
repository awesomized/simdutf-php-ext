#ifndef PHP_SIMDUTF_CONVERT_UTF32_H
#define PHP_SIMDUTF_CONVERT_UTF32_H

#include "../php_simdutf.h"

BEGIN_EXTERN_C()

PHP_FUNCTION(SimdUtf_convert_utf32_to_utf8);
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16);
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16le);
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16be);
PHP_FUNCTION(SimdUtf_convert_utf32_to_latin1);

PHP_FUNCTION(SimdUtf_convert_utf32_to_utf8_with_errors);
PHP_FUNCTION(SimdUtf_convert_utf32_to_latin1_with_errors);
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16_with_errors);
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16le_with_errors);
PHP_FUNCTION(SimdUtf_convert_utf32_to_utf16be_with_errors);

PHP_FUNCTION(SimdUtf_convert_valid_utf32_to_latin1); // missing from simdutf-rs, but present in simdutf?
PHP_FUNCTION(SimdUtf_convert_valid_utf32_to_utf8);
PHP_FUNCTION(SimdUtf_convert_valid_utf32_to_utf16);
PHP_FUNCTION(SimdUtf_convert_valid_utf32_to_utf16le);
PHP_FUNCTION(SimdUtf_convert_valid_utf32_to_utf16be);

END_EXTERN_C()

#endif
