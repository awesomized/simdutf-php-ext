--TEST--
Binary to base64 error handling
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('Skip: simdutf extension not loaded');
?>
--FILE--
<?php
// difficult to craft an overflow test on a 64-bit system without exhausting memory... so just test some edge cases

// Test with NULL bytes
$null_data = "Test\0Data";
var_dump(\SimdUtf\binary_to_base64($null_data));

// Test with all possible byte values
$all_bytes = '';
for ($i = 0; $i < 256; $i++) {
    $all_bytes .= chr($i);
}
$encoded = \SimdUtf\binary_to_base64($all_bytes);
$decoded = base64_decode($encoded); // Use PHP's built-in function to verify
var_dump($decoded === $all_bytes);
?>
--EXPECTF--
string(12) "VGVzdABEYXRh"
bool(true)
