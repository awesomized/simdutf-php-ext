--TEST--
Base64 to binary error handling
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('Skip: simdutf extension not loaded');
?>
--FILE--
<?php
// Test invalid characters
try {
    \SimdUtf\base64_to_binary("SGVs!bG8=");
} catch (Exception $e) {
    echo "Invalid char exception: " . $e->getMessage() . "\n";
}

// Test invalid length
try {
    \SimdUtf\base64_to_binary("SGVsbG8=====");
} catch (Exception $e) {
    echo "Invalid length exception: " . $e->getMessage() . "\n";
}

// Test truncated input
try {
    \SimdUtf\base64_to_binary("SGVsb");
} catch (Exception $e) {
    echo "Truncated input exception: " . $e->getMessage() . "\n";
}

// Test invalid padding
try {
    \SimdUtf\base64_to_binary("SGVsbG8=a");
} catch (Exception $e) {
    echo "Invalid padding exception: " . $e->getMessage() . "\n";
}
?>
--EXPECTF--
Invalid char exception: Invalid base64 character at position %d
Invalid length exception: Invalid base64 character at position 7
Truncated input exception: Invalid base64 input length
Invalid padding exception: Invalid base64 character at position %d
