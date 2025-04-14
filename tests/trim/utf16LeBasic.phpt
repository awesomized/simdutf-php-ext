--TEST--
UTF-16LE trim functionality
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not loaded');
?>
--FILE--
<?php
// Test empty string
var_dump(\SimdUtf\trim_partial_utf16le(''));

// Test basic ASCII string
$utf16le = mb_convert_encoding('Hello', 'UTF-16LE');
var_dump(bin2hex(\SimdUtf\trim_partial_utf16le($utf16le)));

// Test with emoji (complete surrogate pair)
$utf16le_emoji = mb_convert_encoding('Hello😀', 'UTF-16LE');
var_dump(bin2hex(\SimdUtf\trim_partial_utf16le($utf16le_emoji)));

// Test partial surrogate pair
$partial = $utf16le . "\x00\xD8";
var_dump(bin2hex(\SimdUtf\trim_partial_utf16le($partial)));

// Test with null bytes
$with_null = mb_convert_encoding("Hello\0World", 'UTF-16LE');
var_dump(bin2hex(\SimdUtf\trim_partial_utf16le($with_null)));
?>
--EXPECT--
string(0) ""
string(20) "480065006c006c006f00"
string(28) "480065006c006c006f003dd800de"
string(20) "480065006c006c006f00"
string(44) "480065006c006c006f00000057006f0072006c006400"
