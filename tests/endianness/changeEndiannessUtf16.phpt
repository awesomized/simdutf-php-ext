--TEST--
Basic functionality test for \SimdUtf\change_endianness_utf16
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not available');
?>
--FILE--
<?php
// Test 1: Basic ASCII characters in UTF-16LE
$input_le = "\x41\x00\x42\x00\x43\x00"; // "ABC" in UTF-16LE
$result = bin2hex(\SimdUtf\change_endianness_utf16($input_le));
echo "Test 1 (LE to BE): ", $result, "\n";

// Test 2: Basic ASCII characters in UTF-16BE
$input_be = "\x00\x41\x00\x42\x00\x43"; // "ABC" in UTF-16BE
$result = bin2hex(\SimdUtf\change_endianness_utf16($input_be));
echo "Test 2 (BE to LE): ", $result, "\n";

// Test 3: Non-ASCII characters in UTF-16LE
$input_le = "\x24\x27\x0A\x26"; // "₤" (0x2724) and "☺" (0x260A) in UTF-16LE
$result = bin2hex(\SimdUtf\change_endianness_utf16($input_le));
echo "Test 3 (LE to BE - special chars): ", $result, "\n";

// Test 4: Empty string
$result = bin2hex(\SimdUtf\change_endianness_utf16(""));
echo "Test 4 (empty string): ", $result, "\n";
?>
--EXPECT--
Test 1 (LE to BE): 004100420043
Test 2 (BE to LE): 410042004300
Test 3 (LE to BE - special chars): 2724260a
Test 4 (empty string):
