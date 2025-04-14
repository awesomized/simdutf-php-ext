--TEST--
Edge cases for \SimdUtf\detect_encodings
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not available');
?>
--FILE--
<?php
// Test with null bytes
var_dump(\SimdUtf\detect_encodings("\0\0\0\0"));

// Test with very large string
$large_string = str_repeat('A', 1000000);
var_dump(\SimdUtf\detect_encodings($large_string));

// Test with invalid sequences in multiple encodings
$invalid_string = "\xFF\xFF\xFF\xFF";
var_dump(\SimdUtf\detect_encodings($invalid_string));

// Test with mixed valid/invalid content
$mixed_string = "Hello\xFF世界";
var_dump(\SimdUtf\detect_encodings($mixed_string));

// Test with binary data
$binary_data = file_get_contents('/dev/urandom', false, null, 0, 100);
var_dump(\SimdUtf\detect_encodings($binary_data));
?>
--EXPECTF--
int(%d)
int(%d)
int(%d)
int(%d)
int(%d)
