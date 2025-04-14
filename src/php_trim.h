#ifndef PHP_SIMDUTF_TRIM_H
#define PHP_SIMDUTF_TRIM_H

#include "../php_simdutf.h"

BEGIN_EXTERN_C()

PHP_FUNCTION(SimdUtf_trim_partial_utf8);
PHP_FUNCTION(SimdUtf_trim_partial_utf16be);
PHP_FUNCTION(SimdUtf_trim_partial_utf16le);
PHP_FUNCTION(SimdUtf_trim_partial_utf16);

END_EXTERN_C()

#endif
