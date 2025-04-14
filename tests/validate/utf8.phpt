--TEST--
\SimdUtf\validate_utf8() function and error handling
--EXTENSIONS--
simdutf
--FILE--
<?php

// Test valid UTF-8 strings
var_dump(\SimdUtf\validate_utf8("Hello, world!")); // ASCII
var_dump(\SimdUtf\validate_utf8("Hello, 世界!")); // Mixed ASCII and UTF-8
var_dump(\SimdUtf\validate_utf8("🌍🌎🌏")); // Emoji/4-byte sequences
var_dump(\SimdUtf\validate_utf8("")); // Empty string

// Test invalid UTF-8 sequences
var_dump(\SimdUtf\validate_utf8("\xFF")); // Invalid single byte
var_dump(\SimdUtf\validate_utf8("\xC3\x28")); // Invalid 2-byte sequence
var_dump(\SimdUtf\validate_utf8("\xE2\x28\xA1")); // Invalid 3-byte sequence
var_dump(\SimdUtf\validate_utf8("\xF0\x28\x8C\xBC")); // Invalid 4-byte sequence

// Test UTF-8 with detailed error information
$result = \SimdUtf\validate_utf8_with_errors("Hello, 世界!");
var_dump($result);

$result = \SimdUtf\validate_utf8_with_errors("\xFF");
var_dump($result);

?>
--EXPECT--
bool(true)
bool(true)
bool(true)
bool(true)
bool(false)
bool(false)
bool(false)
bool(false)
array(2) {
  ["valid"]=>
  bool(true)
  ["count"]=>
  int(14)
}
array(3) {
  ["valid"]=>
  bool(false)
  ["count"]=>
  int(0)
  ["error"]=>
  string(22) "Invalid UTF-8 sequence"
}
