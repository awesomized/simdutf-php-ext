--TEST--
UTF-16BE trim functionality
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not loaded');
?>
--FILE--
<?php
// Test empty string
var_dump(\SimdUtf\trim_partial_utf16be(''));

// Test basic ASCII string
$utf16be = mb_convert_encoding('Hello', 'UTF-16BE');
var_dump(bin2hex(\SimdUtf\trim_partial_utf16be($utf16be)));

// Test with emoji (complete surrogate pair)
$utf16be_emoji = mb_convert_encoding('Hello😀', 'UTF-16BE');
var_dump(bin2hex(\SimdUtf\trim_partial_utf16be($utf16be_emoji)));

// Test partial surrogate pair
$partial = $utf16be . "\xD8\x00";
var_dump(bin2hex(\SimdUtf\trim_partial_utf16be($partial)));

// Test with null bytes
$with_null = mb_convert_encoding("Hello\0World", 'UTF-16BE');
var_dump(bin2hex(\SimdUtf\trim_partial_utf16be($with_null)));
?>
--EXPECT--
string(0) ""
string(20) "00480065006c006c006f"
string(28) "00480065006c006c006fd83dde00"
string(20) "00480065006c006c006f"
string(44) "00480065006c006c006f00000057006f0072006c0064"
