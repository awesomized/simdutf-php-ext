`awesome/simdutf`
==================

[![Tests status](https://github.com/awesomized/simdutf-php-ext/workflows/Tests/badge.svg)](https://github.com/awesomized/simdutf-php-ext/actions?query=workflow%3ATests)
[![Latest Stable Version](https://img.shields.io/packagist/v/awesome/simdutf)](https://packagist.org/packages/awesome/simdutf)

Unicode and Base64 routines at billions of characters per second in PHP using the [simdutf](https://github.com/simdutf/simdutf) library.

Accelerates Unicode routines (UTF8, UTF16, UTF32) and Base64 using SSE2, AVX2, NEON, AVX-512, RISC-V Vector Extension, LoongArch64, etc. 

The `simdutf` library is already part of Node.js, Bun, WebKit, Chromium, Cloudflare Workers, and more. Now it can be used with PHP.

## Related SIMD-accelerated PHP extensions
* [crc_fast](https://packagist.org/packages/awesome/crc_fast) PHP extension for SIMD-accelerated CRC calculations
  at >100GiB/s.
* [simdjson_plus](https://packagist.org/packages/awesome/simdjson_plus) PHP extension for parsing gigabytes of JSON per second using the
  [simdjson](https://github.com/simdjson/simdjson) project.

## Changes

See the [change log](CHANGELOG.md).

## Installing

Use [Composer](https://getcomposer.org) to install this library using [PIE](https://github.com/php/pie):

```bash
composer install awesome/simdutf
```

## Building

Like most `PHP` extensions, you can also build yourself:

```bash
$ phpize
$ ./configure
$ make
$ make test
$ make install
```

And add the following line to your `php.ini`:

```
extension=simdutf.so
```

## Usage

Supplies all the [simdutf API](https://github.com/simdutf/simdutf#api) functions as PHP functions in the `SimdUtf` namespace (e.g., `simdutf::validate_utf8()` becomes `\SimdUtf\validate_utf8()`).

See the [stubs file](simdutf.stub.php) for a complete list of functions.

## References
* [simdutf](https://github.com/simdutf/simdutf) the `simdutf` library
* [simdutf-rs](https://github.com/Nugine/simdutf-rs) the Rust bindings for `simdutf`