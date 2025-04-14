--TEST--
Edge cases for \SimdUtf\autodetect_encoding
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not available');
?>
--FILE--
<?php
// Test with null byte
var_dump(\SimdUtf\autodetect_encoding("\0"));

// Test with very large string
$large_string = str_repeat('A', 1000000);
var_dump(\SimdUtf\autodetect_encoding($large_string));

// Test with mixed encodings (should detect the predominant one)
$mixed_string = "Hello" . mb_convert_encoding("World", 'UTF-16LE', 'UTF-8');
var_dump(\SimdUtf\autodetect_encoding($mixed_string));

// Test with invalid UTF-8 sequence
$invalid_utf8 = "Hello \xFF\xFF World";
var_dump(\SimdUtf\autodetect_encoding($invalid_utf8));

// Test with binary data
$binary_data = file_get_contents('/dev/urandom', false, null, 0, 100);
var_dump(\SimdUtf\autodetect_encoding($binary_data));
?>
--EXPECTF--
int(1)
int(1)
int(%d)
int(%d)
int(%d)
