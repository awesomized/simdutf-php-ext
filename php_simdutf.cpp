extern "C" {
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "zend_exceptions.h"
#include "main/SAPI.h"
#include "ext/standard/info.h"

#include "php_simdutf.h"
}

#include "simdutf.h"
#include "simdutf_arginfo.h"

PHP_RINIT_FUNCTION(simdutf)
{
#if defined(ZTS) && defined(COMPILE_DL_SIMDUTF_PHP_EXT)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif
    return SUCCESS;
}

PHP_MINFO_FUNCTION(simdutf)
{
    const simdutf::implementation *impl = simdutf::get_active_implementation();

    php_info_print_table_start();
    php_info_print_table_row(2, "simdutf support", "enabled");
    php_info_print_table_row(2, "simdutf extension version", PHP_SIMDUTF_VERSION);
    php_info_print_table_row(2, "simdutf extension support", PHP_SIMDUTF_SUPPORT_URL);
    php_info_print_table_row(2, "simdutf library version", SIMDUTF_VERSION);
    php_info_print_table_row(2, "simdutf implementation name", impl->name().c_str());
    php_info_print_table_row(2, "simdutf implementation description", impl->description().c_str());
    php_info_print_table_end();
}

/* Module initialization */
PHP_MINIT_FUNCTION(simdutf)
{
 // Register encoding type constants
    REGISTER_LONG_CONSTANT("SIMDUTF_ENCODING_UNSPECIFIED", PHP_SIMDUTF_ENCODING_UNSPECIFIED, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SIMDUTF_ENCODING_UTF8", PHP_SIMDUTF_ENCODING_UTF8, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SIMDUTF_ENCODING_UTF16_LE", PHP_SIMDUTF_ENCODING_UTF16_LE, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SIMDUTF_ENCODING_UTF16_BE", PHP_SIMDUTF_ENCODING_UTF16_BE, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SIMDUTF_ENCODING_UTF32_LE", PHP_SIMDUTF_ENCODING_UTF32_LE, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("SIMDUTF_ENCODING_UTF32_BE", PHP_SIMDUTF_ENCODING_UTF32_BE, CONST_CS | CONST_PERSISTENT);

    return SUCCESS;
}

/* Module entry */
zend_module_entry simdutf_module_entry = {
    STANDARD_MODULE_HEADER,
    "simdutf",
    ext_functions,
    PHP_MINIT(simdutf),
    NULL,
    PHP_RINIT(simdutf),
    NULL,
    PHP_MINFO(simdutf),
    PHP_SIMDUTF_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SIMDUTF
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(simdutf)
#endif
