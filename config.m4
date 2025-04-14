dnl config.m4 for extension simdutf

PHP_ARG_ENABLE(simdutf, whether to enable simdutf, [ --enable-simdutf   Enable simdutf])

if test "$PHP_SIMDUTF" != "no"; then

  PHP_REQUIRE_CXX()

  AC_MSG_CHECKING([PHP version])

  if test -z "$PHP_CONFIG"; then
    AC_MSG_ERROR([php-config not found])
  fi
  php_version=`$PHP_CONFIG --vernum`

  if test -z "$php_version"; then
    AC_MSG_ERROR([failed to detect PHP version, please report])
  fi

  if test "$php_version" -lt "80100"; then
    AC_MSG_ERROR([You need at least PHP 8.1.0 to be able to use this version of simdutf. PHP $php_version found])
  else
    AC_MSG_RESULT([$php_version, ok])
  fi

  dnl Mark symbols hidden by default if the compiler (for example, gcc >= 4)
  dnl supports it. This can help reduce the binary size and startup time.
  AX_CHECK_COMPILE_FLAG([-fvisibility=hidden],
                        [CXXFLAGS="$CXXFLAGS -fvisibility=hidden"])

  AC_DEFINE(HAVE_SIMDUTF, 1, [whether simdutf is enabled])
  dnl Disable exceptions because PHP is written in C and loads this C++ module, handle errors manually.
  dnl Disable development checks of C simdutf library in php debug builds (can manually override)
  PHP_NEW_EXTENSION(simdutf, [
      php_simdutf.cpp \
      src/php_base64.cpp \
      src/php_validate.cpp \
      src/php_count.cpp \
      src/php_convert_latin1.cpp \
      src/php_convert_utf8.cpp \
      src/php_convert_utf16.cpp \
      src/php_convert_utf32.cpp \
      src/php_length.cpp \
      src/php_endianness.cpp \
      src/php_trim.cpp \
      src/php_encoding.cpp \
      src/simdutf.cpp],
    $ext_shared,, "-std=c++17 -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1", cxx)

  PHP_ADD_INCLUDE($ext_srcdir/src)

  PHP_INSTALL_HEADERS([ext/simdutf], [php_simdutf.h])
  PHP_ADD_MAKEFILE_FRAGMENT
  PHP_ADD_BUILD_DIR(src, 1)
fi
