--TEST--
Performance test for \SimdUtf\change_endianness_utf16 with large input
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not available');
?>
--FILE--
<?php
// Create a large input string (10000 characters in UTF-16LE)
$input = str_repeat("\x41\x00", 10000); // "A" repeated in UTF-16LE
$start = microtime(true);
$result = \SimdUtf\change_endianness_utf16($input);
$end = microtime(true);

// Verify first few bytes
echo "First 6 bytes: ", bin2hex(substr($result, 0, 6)), "\n";
echo "Time taken: ", number_format($end - $start, 6), " seconds\n";
echo "Input length: ", strlen($input), " bytes\n";
echo "Output length: ", strlen($result), " bytes\n";
?>
--EXPECTF--
First 6 bytes: 004100410041
Time taken: %f seconds
Input length: 20000 bytes
Output length: 20000 bytes
