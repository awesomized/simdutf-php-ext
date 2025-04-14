--TEST--
Memory management with large strings
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not loaded');
?>
--FILE--
<?php
// Test large UTF-8 string
$large_utf8 = str_repeat('A', 1024 * 1024) . "\xE2\x82";
$result_utf8 = \SimdUtf\trim_partial_utf8($large_utf8);
echo "UTF-8 length: ", strlen($result_utf8), "\n";

// Test large UTF-16BE string
$large_utf16be = str_repeat("\x00A", 1024 * 512) . "\xD8\x00";
$result_utf16be = \SimdUtf\trim_partial_utf16be($large_utf16be);
echo "UTF-16BE length: ", strlen($result_utf16be), "\n";

// Test large UTF-16LE string
$large_utf16le = str_repeat("A\x00", 1024 * 512) . "\x00\xD8";
$result_utf16le = \SimdUtf\trim_partial_utf16le($large_utf16le);
echo "UTF-16LE length: ", strlen($result_utf16le), "\n";
?>
--EXPECT--
UTF-8 length: 1048576
UTF-16BE length: 1048576
UTF-16LE length: 1048576
