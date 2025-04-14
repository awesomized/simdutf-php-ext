--TEST--
\SimdUtf\validate_utf16() functions and error handling
--EXTENSIONS--
simdutf
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

// Test valid UTF-16LE strings
var_dump(\SimdUtf\validate_utf16le(str_to_utf16le("Hello, world!"))); // ASCII
var_dump(\SimdUtf\validate_utf16le(str_to_utf16le("Hello, 世界!"))); // Mixed
var_dump(\SimdUtf\validate_utf16le(str_to_utf16le("🌍"))); // Surrogate pairs
var_dump(\SimdUtf\validate_utf16le(str_to_utf16le(""))); // Empty string

// Test valid UTF-16BE strings
var_dump(\SimdUtf\validate_utf16be(str_to_utf16be("Hello, world!"))); // ASCII
var_dump(\SimdUtf\validate_utf16be(str_to_utf16be("Hello, 世界!"))); // Mixed
var_dump(\SimdUtf\validate_utf16be(str_to_utf16be("🌍"))); // Surrogate pairs
var_dump(\SimdUtf\validate_utf16be(str_to_utf16be(""))); // Empty string

// Test invalid UTF-16 cases
try {
    \SimdUtf\validate_utf16le("a"); // Odd length
} catch (Exception $e) {
    echo $e->getMessage() . "\n";
}

// Test valid UTF-16LE with errors
$result = \SimdUtf\validate_utf16le_with_errors(str_to_utf16le("Hello, world!"));
var_dump($result);

// Test another valid string
$result = \SimdUtf\validate_utf16le_with_errors(str_to_utf16le("ab"));
var_dump($result);

?>
--EXPECT--
bool(true)
bool(true)
bool(true)
bool(true)
bool(true)
bool(true)
bool(true)
bool(true)
UTF-16LE string length must be even
array(2) {
  ["valid"]=>
  bool(true)
  ["count"]=>
  int(13)
}
array(2) {
  ["valid"]=>
  bool(true)
  ["count"]=>
  int(2)
}
