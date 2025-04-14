--TEST--
Error handling test for \SimdUtf\change_endianness_utf16
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not available');
?>
--FILE--
<?php
// Test 1: Odd length input
try {
    \SimdUtf\change_endianness_utf16("ABC");
    echo "Should not reach here\n";
} catch (Exception $e) {
    echo "Test 1 (odd length): ", $e->getMessage(), "\n";
}

// Test 2: Single byte input
try {
    \SimdUtf\change_endianness_utf16("A");
    echo "Should not reach here\n";
} catch (Exception $e) {
    echo "Test 2 (single byte): ", $e->getMessage(), "\n";
}

// Test 3: NULL byte test
$input = "\x00\x00\x00\x00";
$result = bin2hex(\SimdUtf\change_endianness_utf16($input));
echo "Test 3 (NULL bytes): ", $result, "\n";
?>
--EXPECT--
Test 1 (odd length): Input length must be even (UTF-16 requires 2 bytes per code unit)
Test 2 (single byte): Input length must be even (UTF-16 requires 2 bytes per code unit)
Test 3 (NULL bytes): 00000000
