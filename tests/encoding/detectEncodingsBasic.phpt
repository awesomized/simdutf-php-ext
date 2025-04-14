--TEST--
Basic test for \SimdUtf\detect_encodings
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not available');
?>
--FILE--
<?php
// Test empty string
var_dump(\SimdUtf\detect_encodings(''));

// Test ASCII string (should be valid in multiple encodings)
var_dump(\SimdUtf\detect_encodings('Hello World'));

// Test UTF-8 string with non-ASCII characters
$utf8_string = "Hello 世界";
var_dump(\SimdUtf\detect_encodings($utf8_string));

// Test string that's valid in both UTF-8 and UTF-16LE
$ambiguous_string = "AB";  // This could be valid in multiple encodings
var_dump(\SimdUtf\detect_encodings($ambiguous_string));

// Test clearly UTF-16LE string
$utf16le_string = mb_convert_encoding("Hello∑漢", 'UTF-16LE', 'UTF-8');
var_dump(\SimdUtf\detect_encodings($utf16le_string));
?>
--EXPECTF--
int(0)
int(%d)
int(%d)
int(%d)
int(%d)
