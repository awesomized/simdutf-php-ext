--TEST--
Basic UTF-8 trim functionality
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not loaded');
?>
--FILE--
<?php
// Test empty string
var_dump(\SimdUtf\trim_partial_utf8(''));

// Test complete valid UTF-8
var_dump(bin2hex(\SimdUtf\trim_partial_utf8('Hello World')));

// Test partial UTF-8 at end (partial euro symbol)
var_dump(bin2hex(\SimdUtf\trim_partial_utf8("Hello\xE2\x82")));

// Test string with emoji
var_dump(bin2hex(\SimdUtf\trim_partial_utf8("Hello 😀 World")));

// Test partial at end (partial emoji)
var_dump(bin2hex(\SimdUtf\trim_partial_utf8("Test\xF0\x9F\x98")));

// Test multiple partials
var_dump(bin2hex(\SimdUtf\trim_partial_utf8("Test\xE2\x82\xAC\xF0\x9F\x98")));
?>
--EXPECT--
string(0) ""
string(22) "48656c6c6f20576f726c64"
string(10) "48656c6c6f"
string(32) "48656c6c6f20f09f988020576f726c64"
string(8) "54657374"
string(14) "54657374e282ac"
