--TEST--
Basic test for \SimdUtf\autodetect_encoding
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not available');
?>
--FILE--
<?php

// Note that \SimdUtf\autodetect_encoding only returns LE types (UTF-16LE, UTF-32LE).

// Test empty string
var_dump(\SimdUtf\autodetect_encoding(''));

// Test ASCII string (should be detected as UTF8)
var_dump(\SimdUtf\autodetect_encoding('Hello World'));

// Test UTF-8 string with non-ASCII characters
$utf8_string = "Hello 世界";  // UTF-8 encoded string
var_dump(\SimdUtf\autodetect_encoding($utf8_string));

// Test UTF-16LE string (explicit binary representation)
$utf16le_string = "\x00\xD8\x00\xDC";  // uses a surrogate pair that's valid in UTF-16LE but not in UTF-8
var_dump(\SimdUtf\autodetect_encoding($utf16le_string));

// Test UTF-32LE string
$utf32le_string = "\xFF\xFE\x00\x00" // BOM
    . "\x37\x04\x01\x00" .  // U+10437
   "\x38\x04\x01\x00" .  // U+10438
   "\x39\x04\x01\x00";
var_dump(\SimdUtf\autodetect_encoding($utf32le_string));
?>
--EXPECTF--
int(0)
int(1)
int(1)
int(2)
int(8)
