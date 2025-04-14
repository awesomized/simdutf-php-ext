#ifndef PHP_SIMDUTF_BASE64_H
#define PHP_SIMDUTF_BASE64_H

#include "../php_simdutf.h"

BEGIN_EXTERN_C()

PHP_FUNCTION(SimdUtf_binary_to_base64);
PHP_FUNCTION(SimdUtf_base64_to_binary);
PHP_FUNCTION(SimdUtf_base64_to_binary_safe);

END_EXTERN_C()

#endif
