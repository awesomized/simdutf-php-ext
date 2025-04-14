--TEST--
UTF-16 native trim functionality
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not loaded');
?>
--FILE--
<?php
// Determine system endianness
$isLittleEndian = pack('S', 1) === pack('v', 1);
$encoding = $isLittleEndian ? 'UTF-16LE' : 'UTF-16BE';

// Test empty string
var_dump(\SimdUtf\trim_partial_utf16(''));

// Test basic ASCII string
$utf16 = mb_convert_encoding('Hello', $encoding);
var_dump(bin2hex(\SimdUtf\trim_partial_utf16($utf16)));

// Test with emoji
$utf16_emoji = mb_convert_encoding('Hello😀', $encoding);
var_dump(bin2hex(\SimdUtf\trim_partial_utf16($utf16_emoji)));

// Test partial surrogate pair
$partial = $utf16 . ($isLittleEndian ? "\x00\xD8" : "\xD8\x00");
var_dump(bin2hex(\SimdUtf\trim_partial_utf16($partial)));

// Output endianness for verification
echo "System is ", $isLittleEndian ? "little" : "big", "-endian\n";
?>
--EXPECTF--
string(0) ""
string(20) "480065006c006c006f00"
string(28) "480065006c006c006f003dd800de"
string(20) "480065006c006c006f00"
System is %s-endian
