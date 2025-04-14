#ifndef PHP_SIMDUTF_H
#define PHP_SIMDUTF_H

#include "Zend/zend.h"
#include "Zend/zend_portability.h"

BEGIN_EXTERN_C()

/* Error constants */
#define SIMDUTF_PHP_ERR_SUCCESS 0
#define SIMDUTF_PHP_ERR_INVALID_PHP_PROPERTY 255
#define SIMDUTF_PHP_ERR_KEY_COUNT_NOT_COUNTABLE 254

extern zend_module_entry simdutf_module_entry;
#define phpext_simdutf_ptr &simdutf_module_entry

#define PHP_SIMDUTF_VERSION                  "1.0.0"
#define PHP_SIMDUTF_VERSION_ID               10000
#define PHP_SIMDUTF_SUPPORT_URL              "https://github.com/awesomized/simdutf-php-ext"

#define PHP_SIMDUTF_ENCODING_UNSPECIFIED 0
#define PHP_SIMDUTF_ENCODING_UTF8        1
#define PHP_SIMDUTF_ENCODING_UTF16_LE    2
#define PHP_SIMDUTF_ENCODING_UTF16_BE    4
#define PHP_SIMDUTF_ENCODING_UTF32_LE    8
#define PHP_SIMDUTF_ENCODING_UTF32_BE    16

/* Module functions */
PHP_MINIT_FUNCTION(simdutf);
PHP_MSHUTDOWN_FUNCTION(simdutf);
PHP_RINIT_FUNCTION(simdutf);
PHP_RSHUTDOWN_FUNCTION(simdutf);
PHP_MINFO_FUNCTION(simdutf);

#ifdef ZTS
#ifdef COMPILE_DL_SIMDUTF
ZEND_TSRMLS_CACHE_EXTERN()
#endif
#endif

/* Include component headers */
#include "src/php_base64.h"
#include "src/php_validate.h"
#include "src/php_convert_latin1.h"
#include "src/php_convert_utf8.h"
#include "src/php_convert_utf16.h"
#include "src/php_convert_utf32.h"
#include "src/php_count.h"
#include "src/php_length.h"
#include "src/php_trim.h"
#include "src/php_endianness.h"
#include "src/php_encoding.h"

END_EXTERN_C()

#endif /* PHP_SIMDUTF_H */
