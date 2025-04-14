--TEST--
UTF-8 trim edge cases and invalid sequences
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not loaded');
?>
--FILE--
<?php
// Test all invalid sequences
var_dump(bin2hex(\SimdUtf\trim_partial_utf8("\xE2\x28\xA1")));

// Test mixed valid and invalid with partial ending
var_dump(bin2hex(\SimdUtf\trim_partial_utf8("Valid\xE2\x28\xA1Partial\xF0\x9F")));

// Test large string with partial ending
$large = str_repeat('A', 1024) . "\xE2\x82";
var_dump(strlen(\SimdUtf\trim_partial_utf8($large)));

// Test null bytes
var_dump(bin2hex(\SimdUtf\trim_partial_utf8("Hello\x00World\xE2\x82")));
?>
--EXPECT--
string(6) "e228a1"
string(30) "56616c6964e228a15061727469616c"
int(1024)
string(22) "48656c6c6f00576f726c64"
