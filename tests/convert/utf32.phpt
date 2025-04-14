--TEST--
simdutf UTF-32 conversion functions
--SKIPIF--
<?php if (!extension_loaded('simdutf')) die('skip simdutf extension not available'); ?>
--FILE--
<?php
// Helper function to create UTF-32LE string (assuming little-endian system)
function create_utf32_string($codepoints) {
    $result = '';
    foreach ($codepoints as $cp) {
        $result .= pack('V', $cp);
    }
    return $result;
}

// Test basic ASCII conversion
echo "=== UTF-32 Basic ASCII ===\n";
$utf32_hello = create_utf32_string([
    0x48, 0x65, 0x6C, 0x6C, 0x6F  // "Hello"
]);

// Convert to various encodings
$utf8 = \SimdUtf\convert_utf32_to_utf8($utf32_hello);
$utf16le = \SimdUtf\convert_utf32_to_utf16le($utf32_hello);
$utf16be = \SimdUtf\convert_utf32_to_utf16be($utf32_hello);
$latin1 = \SimdUtf\convert_utf32_to_latin1($utf32_hello);

echo "Original UTF-32: ", bin2hex($utf32_hello), "\n";
echo "UTF-8: ", bin2hex($utf8), "\n";
echo "UTF-16LE: ", bin2hex($utf16le), "\n";
echo "UTF-16BE: ", bin2hex($utf16be), "\n";
echo "Latin1: ", bin2hex($latin1), "\n";

// Test with empty string
echo "\n=== Empty String ===\n";
var_dump(\SimdUtf\convert_utf32_to_utf8(''));
var_dump(\SimdUtf\convert_utf32_to_utf16le(''));
var_dump(\SimdUtf\convert_utf32_to_utf16be(''));
var_dump(\SimdUtf\convert_utf32_to_latin1(''));

// Test with non-ASCII Unicode characters
echo "\n=== Unicode Characters ===\n";
$utf32_unicode = create_utf32_string([
    0x48, 0x65, 0x6C, 0x6C, 0x6F, // "Hello"
    0x20,                         // space
    0x2603,                       // SNOWMAN (☃)
    0x20,                         // space
    0x57, 0x6F, 0x72, 0x6C, 0x64  // "World"
]);

$utf8_unicode = \SimdUtf\convert_utf32_to_utf8($utf32_unicode);
echo "UTF-32 with snowman: ", bin2hex($utf32_unicode), "\n";
echo "UTF-8 with snowman: ", bin2hex($utf8_unicode), "\n";

// Test high unicode/emoji (requiring surrogate pairs in UTF-16)
echo "\n=== High Unicode/Emoji ===\n";
$utf32_emoji = create_utf32_string([
    0x1F603  // SMILING FACE WITH OPEN MOUTH (😃)
]);

$utf8_emoji = \SimdUtf\convert_utf32_to_utf8($utf32_emoji);
$utf16le_emoji = \SimdUtf\convert_utf32_to_utf16le($utf32_emoji);
echo "UTF-32 emoji: ", bin2hex($utf32_emoji), "\n";
echo "UTF-8 emoji: ", bin2hex($utf8_emoji), "\n";
echo "UTF-16LE emoji: ", bin2hex($utf16le_emoji), "\n";

// Test error cases
echo "\n=== Error Cases ===\n";
// Test invalid length
try {
    \SimdUtf\convert_utf32_to_utf8('abc');
} catch (Exception $e) {
    echo $e->getMessage(), "\n";
}

// Test conversion with errors
echo "\n=== Conversion with Errors ===\n";
$invalid_utf32 = "\xFF\xFF\xFF\xFF"; // Invalid UTF-32 value
$result = \SimdUtf\convert_utf32_to_utf8_with_errors($invalid_utf32);
var_dump($result);

// Test conversion with Unicode values above 0x10FFFF (invalid)
$invalid_high = create_utf32_string([0x110000]); // First invalid Unicode value
$result = \SimdUtf\convert_utf32_to_utf8_with_errors($invalid_high);
var_dump($result);

// Test NULL byte handling
echo "\n=== NULL Byte Handling ===\n";
$with_null = create_utf32_string([0x61, 0x00, 0x62]); // "a\0b"
$result = \SimdUtf\convert_utf32_to_utf8($with_null);
echo "String with NULL: ", bin2hex($result), "\n";

// Test valid input conversion functions
echo "\n=== Valid Input Conversions ===\n";
$valid_input = create_utf32_string([0x48, 0x69]); // "Hi"
$result = \SimdUtf\convert_valid_utf32_to_utf8($valid_input);
echo "Valid conversion: ", bin2hex($result), "\n";
?>
--EXPECT--
=== UTF-32 Basic ASCII ===
Original UTF-32: 48000000650000006c0000006c0000006f000000
UTF-8: 48656c6c6f
UTF-16LE: 480065006c006c006f00
UTF-16BE: 00480065006c006c006f
Latin1: 48656c6c6f

=== Empty String ===
bool(false)
bool(false)
bool(false)
bool(false)

=== Unicode Characters ===
UTF-32 with snowman: 48000000650000006c0000006c0000006f000000200000000326000020000000570000006f000000720000006c00000064000000
UTF-8 with snowman: 48656c6c6f20e2988320576f726c64

=== High Unicode/Emoji ===
UTF-32 emoji: 03f60100
UTF-8 emoji: f09f9883
UTF-16LE emoji: 3dd803de

=== Error Cases ===
Input length must be a multiple of 4 bytes

=== Conversion with Errors ===
array(2) {
  ["success"]=>
  bool(false)
  ["error_position"]=>
  int(0)
}
array(2) {
  ["success"]=>
  bool(false)
  ["error_position"]=>
  int(0)
}

=== NULL Byte Handling ===
String with NULL: 610062

=== Valid Input Conversions ===
Valid conversion: 4869
