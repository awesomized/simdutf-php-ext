--TEST--
\SimdUtf\validate_utf32() function and error handling
--EXTENSIONS--
simdutf
--FILE--
<?php

// Create a valid UTF-32 string (using direct byte representation)
function create_utf32_string($codepoints) {
    $result = '';
    foreach ($codepoints as $cp) {
        $result .= pack('V', $cp); // Little-endian representation
    }
    return $result;
}

// Test valid UTF-32 strings
$valid_string = create_utf32_string([
    0x48, 0x65, 0x6C, 0x6C, 0x6F // "Hello"
]);
var_dump(\SimdUtf\validate_utf32($valid_string));

// Test empty string
var_dump(\SimdUtf\validate_utf32(""));

// Test string with emoji (valid codepoint range)
$emoji_string = create_utf32_string([0x1F30D]); // 🌍
var_dump(\SimdUtf\validate_utf32($emoji_string));

// Test invalid length
try {
    \SimdUtf\validate_utf32("abc"); // Not multiple of 4
} catch (Exception $e) {
    echo $e->getMessage() . "\n";
}

// Test invalid codepoint (greater than 0x10FFFF)
$invalid_string = create_utf32_string([0x110000]);
var_dump(\SimdUtf\validate_utf32($invalid_string));

// Test with detailed error information for valid string
$result = \SimdUtf\validate_utf32_with_errors($valid_string);
var_dump($result);

// Test with detailed error information for invalid string
$result = \SimdUtf\validate_utf32_with_errors($invalid_string);
var_dump($result);

?>
--EXPECT--
bool(true)
bool(true)
bool(true)
UTF-32 string length must be a multiple of 4
bool(false)
array(2) {
  ["valid"]=>
  bool(true)
  ["count"]=>
  int(5)
}
array(3) {
  ["valid"]=>
  bool(false)
  ["count"]=>
  int(0)
  ["error"]=>
  string(23) "Invalid UTF-32 sequence"
}
