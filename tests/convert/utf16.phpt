--TEST--
simdutf UTF-16 conversion functions
--SKIPIF--
<?php if (!extension_loaded('simdutf')) die('skip simdutf extension not available'); ?>
--FILE--
<?php
// Helper function to create UTF-16LE string
function str_to_utf16le($str) {
    return mb_convert_encoding($str, 'UTF-16LE', 'UTF-8');
}

// Helper function to create UTF-16BE string
function str_to_utf16be($str) {
    return mb_convert_encoding($str, 'UTF-16BE', 'UTF-8');
}

// Test UTF-16LE to UTF-8
echo "=== UTF-16LE to UTF-8 ===\n";
$utf16le = str_to_utf16le("Hello © World");
$utf8 = \SimdUtf\convert_utf16le_to_utf8($utf16le);
echo "Original UTF-16LE: ", bin2hex($utf16le), "\n";
echo "UTF-8: ", bin2hex($utf8), "\n";

// Test empty string
var_dump(\SimdUtf\convert_utf16le_to_utf8(''));

// Test UTF-16BE to UTF-8
echo "\n=== UTF-16BE to UTF-8 ===\n";
$utf16be = str_to_utf16be("Hello © World");
$utf8 = \SimdUtf\convert_utf16be_to_utf8($utf16be);
echo "Original UTF-16BE: ", bin2hex($utf16be), "\n";
echo "UTF-8: ", bin2hex($utf8), "\n";

// Test with surrogate pairs (emoji)
echo "\n=== Surrogate Pairs ===\n";
$utf16le_emoji = str_to_utf16le("Hello 🌟 World");
$utf8_emoji = \SimdUtf\convert_utf16le_to_utf8($utf16le_emoji);
echo "Emoji UTF-8: ", bin2hex($utf8_emoji), "\n";

// Test conversions to Latin1
echo "\n=== UTF-16 to Latin1 ===\n";
$utf16le_simple = str_to_utf16le("Hello World");
$latin1 = \SimdUtf\convert_utf16le_to_latin1($utf16le_simple);
echo "Latin1: ", bin2hex($latin1), "\n";

// Test error cases
echo "\n=== Error Cases ===\n";
// Test odd length input
try {
    \SimdUtf\convert_utf16le_to_utf8('abc');
} catch (Exception $e) {
    echo $e->getMessage(), "\n";
}

// Test invalid surrogate pairs
$invalid_surrogate = "\x00\xD8\x00\x00"; // High surrogate without low surrogate
var_dump(\SimdUtf\convert_utf16le_to_utf8($invalid_surrogate));

// Test conversion with errors
echo "\n=== Conversion with Errors ===\n";
$result = \SimdUtf\convert_utf16le_to_utf8_with_errors($invalid_surrogate);
var_dump($result);

// Test UTF-16 to UTF-32 conversion
echo "\n=== UTF-16 to UTF-32 ===\n";
$utf16le = str_to_utf16le("Hello World");
$utf32 = \SimdUtf\convert_utf16le_to_utf32($utf16le);
echo "UTF-32: ", bin2hex($utf32), "\n";

// Test valid input conversion functions
echo "\n=== Valid Input Conversions ===\n";
$valid_utf16le = str_to_utf16le("Hello World");
$utf8 = \SimdUtf\convert_valid_utf16le_to_utf8($valid_utf16le);
echo "Valid UTF-8: ", bin2hex($utf8), "\n";

// Test NULL byte handling
echo "\n=== NULL byte handling ===\n";
$with_null = str_to_utf16le("a\0b");
$result = \SimdUtf\convert_utf16le_to_utf8($with_null);
echo "String with NULL: ", bin2hex($result), "\n";
?>
--EXPECT--
=== UTF-16LE to UTF-8 ===
Original UTF-16LE: 480065006c006c006f002000a900200057006f0072006c006400
UTF-8: 48656c6c6f20c2a920576f726c64
string(0) ""

=== UTF-16BE to UTF-8 ===
Original UTF-16BE: 00480065006c006c006f002000a900200057006f0072006c0064
UTF-8: 48656c6c6f20c2a920576f726c64

=== Surrogate Pairs ===
Emoji UTF-8: 48656c6c6f20f09f8c9f20576f726c64

=== UTF-16 to Latin1 ===
Latin1: 48656c6c6f20576f726c64

=== Error Cases ===
Input length must be even for UTF-16LE
string(0) ""

=== Conversion with Errors ===
array(2) {
  ["success"]=>
  bool(false)
  ["error_offset"]=>
  int(0)
}

=== UTF-16 to UTF-32 ===
UTF-32: 48000000650000006c0000006c0000006f00000020000000570000006f000000720000006c00000064000000

=== Valid Input Conversions ===
Valid UTF-8: 48656c6c6f20576f726c64

=== NULL byte handling ===
String with NULL: 610062
