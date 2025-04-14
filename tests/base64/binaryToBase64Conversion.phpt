--TEST--
Basic binary to base64 conversion
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('Skip: simdutf extension not loaded');
?>
--FILE--
<?php
// Test basic ASCII string
$input = "Hello, World!";
$base64 = \SimdUtf\binary_to_base64($input);
var_dump($base64);

// test matches base64_encode
var_dump($base64 === base64_encode($input));

// Test empty string
var_dump(\SimdUtf\binary_to_base64(""));

// Test binary data
$binary = pack("C*", 255, 254, 253, 252);
var_dump(\SimdUtf\binary_to_base64($binary));

// test matches base64_encode
var_dump(\SimdUtf\binary_to_base64($binary) === base64_encode($binary));

// Test string requiring padding
$pad_test = "ABC";
var_dump(\SimdUtf\binary_to_base64($pad_test));

// Test long string
$long = str_repeat("A", 1000);
$encoded = \SimdUtf\binary_to_base64($long);
// The base64_length_from_binary function includes padding in its calculation
// For 1000 'A' characters:
// - Each 'A' is encoded as 'QQ'
// - The output must be padded to a multiple of 4
// - So we expect the output to be padded with '=='
var_dump(strlen($encoded) === 1336); // 1000 * 4/3 rounded up to multiple of 4

// test matches base64_encode
var_dump($encoded === base64_encode($long));

// Verify that output is valid UTF-8
$encoded = \SimdUtf\binary_to_base64($binary);
var_dump(mb_check_encoding($encoded, 'UTF-8'));
?>
--EXPECT--
string(20) "SGVsbG8sIFdvcmxkIQ=="
bool(true)
string(0) ""
string(8) "//79/A=="
bool(true)
string(4) "QUJD"
bool(true)
bool(true)
bool(true)
