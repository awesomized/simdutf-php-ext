--TEST--
Base64 to binary conversion
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('Skip: simdutf extension not loaded');
?>
--FILE--
<?php

// Test valid base64 string
$base64 = "SGVsbG8sIFdvcmxkIQ==";
var_dump(\SimdUtf\base64_to_binary($base64));

// Test empty string
var_dump(\SimdUtf\base64_to_binary(""));

// Test without padding
var_dump(\SimdUtf\base64_to_binary("SGVsbG8"));

// Test with whitespace (should be ignored)
var_dump(\SimdUtf\base64_to_binary("SG Vs bG8="));

// Test binary data roundtrip
$binary = pack("C*", 255, 254, 253, 252);
$base64 = \SimdUtf\binary_to_base64($binary);
$decoded = \SimdUtf\base64_to_binary($base64);
var_dump($binary === $decoded);
?>
--EXPECT--
string(13) "Hello, World!"
string(0) ""
string(5) "Hello"
string(5) "Hello"
bool(true)
