#ifndef PHP_SIMDUTF_CONVERT_LATIN1_H
#define PHP_SIMDUTF_CONVERT_LATIN1_H

#include "../php_simdutf.h"

BEGIN_EXTERN_C()

PHP_FUNCTION(SimdUtf_convert_latin1_to_utf8);
PHP_FUNCTION(SimdUtf_convert_latin1_to_utf16);
PHP_FUNCTION(SimdUtf_convert_latin1_to_utf16le);
PHP_FUNCTION(SimdUtf_convert_latin1_to_utf16be);
PHP_FUNCTION(SimdUtf_convert_latin1_to_utf32);

END_EXTERN_C()

#endif
