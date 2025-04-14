--TEST--
simdutf Latin1 conversion functions
--SKIPIF--
<?php if (!extension_loaded('simdutf')) die('skip simdutf extension not available'); ?>
--FILE--
<?php
// Test Latin1 to UTF-8 conversion
echo "=== Latin1 to UTF-8 ===\n";
$latin1 = "Hello \xA9 World"; // Latin1 copyright symbol
$utf8 = \SimdUtf\convert_latin1_to_utf8($latin1);
echo "Original: ", bin2hex($latin1), "\n";
echo "UTF-8: ", bin2hex($utf8), "\n";

// Test empty string
var_dump(\SimdUtf\convert_latin1_to_utf8(''));

// Test all Latin1 special chars (0xA0-0xFF)
$all_latin1 = '';
for ($i = 0xA0; $i <= 0xFF; $i++) {
    $all_latin1 .= chr($i);
}
$utf8_all = \SimdUtf\convert_latin1_to_utf8($all_latin1);
echo "All Latin1 length: ", strlen($all_latin1), "\n";
echo "UTF-8 length: ", strlen($utf8_all), "\n";

// Test Latin1 to UTF-16LE
echo "\n=== Latin1 to UTF-16LE ===\n";
$utf16le = \SimdUtf\convert_latin1_to_utf16le($latin1);
echo "UTF-16LE: ", bin2hex($utf16le), "\n";

// Test Latin1 to UTF-16BE
echo "\n=== Latin1 to UTF-16BE ===\n";
$utf16be = \SimdUtf\convert_latin1_to_utf16be($latin1);
echo "UTF-16BE: ", bin2hex($utf16be), "\n";

// Test Latin1 to UTF-32
echo "\n=== Latin1 to UTF-32 ===\n";
$utf32 = \SimdUtf\convert_latin1_to_utf32($latin1);
echo "UTF-32: ", bin2hex($utf32), "\n";

// Test error cases
echo "\n=== NULL byte test ===\n";
$result = \SimdUtf\convert_latin1_to_utf8("\x00");
echo "NULL byte conversion: ", bin2hex($result), "\n";

// Test a string with NULL byte in middle
$result = \SimdUtf\convert_latin1_to_utf8("a\x00b");
echo "String with NULL byte: ", bin2hex($result), "\n";
?>
--EXPECT--
=== Latin1 to UTF-8 ===
Original: 48656c6c6f20a920576f726c64
UTF-8: 48656c6c6f20c2a920576f726c64
string(0) ""
All Latin1 length: 96
UTF-8 length: 192

=== Latin1 to UTF-16LE ===
UTF-16LE: 480065006c006c006f002000a900200057006f0072006c006400

=== Latin1 to UTF-16BE ===
UTF-16BE: 00480065006c006c006f002000a900200057006f0072006c0064

=== Latin1 to UTF-32 ===
UTF-32: 48000000650000006c0000006c0000006f00000020000000a900000020000000570000006f000000720000006c00000064000000

=== NULL byte test ===
NULL byte conversion: 00
String with NULL byte: 610062
