--TEST--
Safe base64 to binary conversion
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('Skip: simdutf extension not loaded');
?>
--FILE--
<?php
// Test with sufficient buffer
$base64 = "SGVsbG8sIFdvcmxkIQ=="; // "Hello, World!"
var_dump(bin2hex(\SimdUtf\base64_to_binary_safe($base64, 20)));

// Test with exact buffer size
var_dump(bin2hex(\SimdUtf\base64_to_binary_safe($base64, 13)));

// Test with insufficient buffer
try {
    \SimdUtf\base64_to_binary_safe($base64, 5);
} catch (Exception $e) {
    echo "Buffer too small: " . $e->getMessage() . "\n";
}

// Test with negative buffer size
try {
    \SimdUtf\base64_to_binary_safe($base64, -1);
} catch (Exception $e) {
    echo "Negative buffer: " . $e->getMessage() . "\n";
}

// Test with invalid input
try {
    \SimdUtf\base64_to_binary_safe("Invalid!Base64", 10);
} catch (Exception $e) {
    echo "Invalid input: " . $e->getMessage() . "\n";
}

// Test with empty input
var_dump(bin2hex(\SimdUtf\base64_to_binary_safe("", 10)));

// Test with whitespace
$spaced = "SGVs bG8s IFdv cmxk IQ==";
var_dump(bin2hex(\SimdUtf\base64_to_binary_safe($spaced, 20)));
?>
--EXPECTF--
string(26) "48656c6c6f2c20576f726c6421"
string(26) "48656c6c6f2c20576f726c6421"
Buffer too small: Output buffer too small. Required size: 4
Negative buffer: Maximum output length cannot be negative
Invalid input: Invalid base64 character at position %d
string(0) ""
string(26) "48656c6c6f2c20576f726c6421"
