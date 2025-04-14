--TEST--
SIMDUTF length functions test suite
--EXTENSIONS--
simdutf
--FILE--
<?php
// Helper function to test and display results
function test_length($func, $input, $desc) {
    echo "\nTesting $func - $desc:\n";
    try {
        $result = $func($input);
        echo "Result: " . $result . "\n";
    } catch (Exception $e) {
        echo "Exception: " . $e->getMessage() . "\n";
    }
}

echo "=== UTF-8 Length Tests ===\n";

// Test UTF-8 length from Latin1
test_length('\SimdUtf\utf8_length_from_latin1', 'Hello World', 'Basic ASCII');
test_length('\SimdUtf\utf8_length_from_latin1', '', 'Empty string');
test_length('\SimdUtf\utf8_length_from_latin1', str_repeat('A', 1000), 'Long ASCII string');
test_length('\SimdUtf\utf8_length_from_latin1', "\xA9", 'Copyright symbol (Latin1)');

// Test Latin1 length from UTF-8
test_length('\SimdUtf\latin1_length_from_utf8', 'Hello World', 'Basic ASCII');
test_length('\SimdUtf\latin1_length_from_utf8', 'Hello © World', 'With copyright symbol');
test_length('\SimdUtf\latin1_length_from_utf8', '', 'Empty string');

// Test UTF-16 length from UTF-8
test_length('\SimdUtf\utf16_length_from_utf8', 'Hello World', 'Basic ASCII');
test_length('\SimdUtf\utf16_length_from_utf8', 'Hello 世界', 'With CJK characters');
test_length('\SimdUtf\utf16_length_from_utf8', '🌟', 'With emoji');
test_length('\SimdUtf\utf16_length_from_utf8', '', 'Empty string');

// Test UTF-32 length from UTF-8
test_length('\SimdUtf\utf32_length_from_utf8', 'Hello World', 'Basic ASCII');
test_length('\SimdUtf\utf32_length_from_utf8', 'Hello 世界', 'With CJK characters');
test_length('\SimdUtf\utf32_length_from_utf8', '🌟', 'With emoji');
test_length('\SimdUtf\utf32_length_from_utf8', '', 'Empty string');

echo "\n=== UTF-16 Length Tests ===\n";

// Create test strings with correct length calculations
$utf16le_str = mb_convert_encoding('Hello World', 'UTF-16LE');
$utf16le_cjk = mb_convert_encoding('Hello 世界', 'UTF-16LE');
$utf16le_emoji = mb_convert_encoding('🌟', 'UTF-16LE');

// Test UTF-8 length from UTF-16LE
test_length('\SimdUtf\utf8_length_from_utf16le', $utf16le_str, 'Basic ASCII');
test_length('\SimdUtf\utf8_length_from_utf16le', $utf16le_cjk, 'With CJK characters');
test_length('\SimdUtf\utf8_length_from_utf16le', $utf16le_emoji, 'With emoji');
test_length('\SimdUtf\utf8_length_from_utf16le', '', 'Empty string');
test_length('\SimdUtf\utf8_length_from_utf16le', 'A', 'Invalid odd length');

// Create UTF-16BE test strings
$utf16be_str = mb_convert_encoding('Hello World', 'UTF-16BE');
$utf16be_cjk = mb_convert_encoding('Hello 世界', 'UTF-16BE');
$utf16be_emoji = mb_convert_encoding('🌟', 'UTF-16BE');

// Test UTF-8 length from UTF-16BE
test_length('\SimdUtf\utf8_length_from_utf16be', $utf16be_str, 'Basic ASCII');
test_length('\SimdUtf\utf8_length_from_utf16be', $utf16be_cjk, 'With CJK characters');
test_length('\SimdUtf\utf8_length_from_utf16be', $utf16be_emoji, 'With emoji');
test_length('\SimdUtf\utf8_length_from_utf16be', '', 'Empty string');
test_length('\SimdUtf\utf8_length_from_utf16be', 'A', 'Invalid odd length');

echo "\n=== UTF-32 Length Tests ===\n";

// Create UTF-32 test strings (using native endianness)
$utf32_str = mb_convert_encoding('Hello World', 'UTF-32');
$utf32_cjk = mb_convert_encoding('Hello 世界', 'UTF-32');
$utf32_emoji = mb_convert_encoding('🌟', 'UTF-32');

// Test UTF-8 length from UTF-32
test_length('\SimdUtf\utf8_length_from_utf32', $utf32_str, 'Basic ASCII');
test_length('\SimdUtf\utf8_length_from_utf32', $utf32_cjk, 'With CJK characters');
test_length('\SimdUtf\utf8_length_from_utf32', $utf32_emoji, 'With emoji');
test_length('\SimdUtf\utf8_length_from_utf32', '', 'Empty string');
test_length('\SimdUtf\utf8_length_from_utf32', 'AA', 'Invalid length');

// Test UTF-32 length from UTF-16
test_length('\SimdUtf\utf32_length_from_utf16', $utf16le_str, 'Basic ASCII');
test_length('\SimdUtf\utf32_length_from_utf16', $utf16le_cjk, 'With CJK characters');
test_length('\SimdUtf\utf32_length_from_utf16', $utf16le_emoji, 'With emoji');
test_length('\SimdUtf\utf32_length_from_utf16', '', 'Empty string');
test_length('\SimdUtf\utf32_length_from_utf16', 'A', 'Invalid odd length');

// Test Latin1 length from UTF-32
test_length('\SimdUtf\latin1_length_from_utf32', $utf32_str, 'Basic ASCII');
test_length('\SimdUtf\latin1_length_from_utf32', '', 'Empty string');
test_length('\SimdUtf\latin1_length_from_utf32', 'AA', 'Invalid length');

?>
--EXPECTF--
=== UTF-8 Length Tests ===

Testing \SimdUtf\utf8_length_from_latin1 - Basic ASCII:
Result: 11

Testing \SimdUtf\utf8_length_from_latin1 - Empty string:
Result: 0

Testing \SimdUtf\utf8_length_from_latin1 - Long ASCII string:
Result: 1000

Testing \SimdUtf\utf8_length_from_latin1 - Copyright symbol (Latin1):
Result: 2

Testing \SimdUtf\latin1_length_from_utf8 - Basic ASCII:
Result: 11

Testing \SimdUtf\latin1_length_from_utf8 - With copyright symbol:
Result: 13

Testing \SimdUtf\latin1_length_from_utf8 - Empty string:
Result: 0

Testing \SimdUtf\utf16_length_from_utf8 - Basic ASCII:
Result: 11

Testing \SimdUtf\utf16_length_from_utf8 - With CJK characters:
Result: 8

Testing \SimdUtf\utf16_length_from_utf8 - With emoji:
Result: 2

Testing \SimdUtf\utf16_length_from_utf8 - Empty string:
Result: 0

Testing \SimdUtf\utf32_length_from_utf8 - Basic ASCII:
Result: 11

Testing \SimdUtf\utf32_length_from_utf8 - With CJK characters:
Result: 8

Testing \SimdUtf\utf32_length_from_utf8 - With emoji:
Result: 1

Testing \SimdUtf\utf32_length_from_utf8 - Empty string:
Result: 0

=== UTF-16 Length Tests ===

Testing \SimdUtf\utf8_length_from_utf16le - Basic ASCII:
Result: 11

Testing \SimdUtf\utf8_length_from_utf16le - With CJK characters:
Result: 12

Testing \SimdUtf\utf8_length_from_utf16le - With emoji:
Result: 4

Testing \SimdUtf\utf8_length_from_utf16le - Empty string:
Result: 0

Testing \SimdUtf\utf8_length_from_utf16le - Invalid odd length:
Exception: UTF-16LE string length must be even

Testing \SimdUtf\utf8_length_from_utf16be - Basic ASCII:
Result: 11

Testing \SimdUtf\utf8_length_from_utf16be - With CJK characters:
Result: 12

Testing \SimdUtf\utf8_length_from_utf16be - With emoji:
Result: 4

Testing \SimdUtf\utf8_length_from_utf16be - Empty string:
Result: 0

Testing \SimdUtf\utf8_length_from_utf16be - Invalid odd length:
Exception: UTF-16BE string length must be even

=== UTF-32 Length Tests ===

Testing \SimdUtf\utf8_length_from_utf32 - Basic ASCII:
Result: 44

Testing \SimdUtf\utf8_length_from_utf32 - With CJK characters:
Result: 32

Testing \SimdUtf\utf8_length_from_utf32 - With emoji:
Result: 4

Testing \SimdUtf\utf8_length_from_utf32 - Empty string:
Result: 0

Testing \SimdUtf\utf8_length_from_utf32 - Invalid length:
Exception: UTF-32 string length must be a multiple of 4

Testing \SimdUtf\utf32_length_from_utf16 - Basic ASCII:
Result: 11

Testing \SimdUtf\utf32_length_from_utf16 - With CJK characters:
Result: 8

Testing \SimdUtf\utf32_length_from_utf16 - With emoji:
Result: 1

Testing \SimdUtf\utf32_length_from_utf16 - Empty string:
Result: 0

Testing \SimdUtf\utf32_length_from_utf16 - Invalid odd length:
Exception: UTF-16 string length must be even

Testing \SimdUtf\latin1_length_from_utf32 - Basic ASCII:
Result: 11

Testing \SimdUtf\latin1_length_from_utf32 - Empty string:
Result: 0

Testing \SimdUtf\latin1_length_from_utf32 - Invalid length:
Exception: UTF-32 string length must be a multiple of 4
