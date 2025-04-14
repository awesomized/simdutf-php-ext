--TEST--
\SimdUtf\validate_ascii() function and error handling
--EXTENSIONS--
simdutf
--FILE--
<?php

// Test valid ASCII strings
var_dump(\SimdUtf\validate_ascii("Hello, world!")); // Pure ASCII
var_dump(\SimdUtf\validate_ascii("")); // Empty string
var_dump(\SimdUtf\validate_ascii("123456789")); // Numbers
var_dump(\SimdUtf\validate_ascii("!@#$%^&*()")); // Special characters

// Test invalid ASCII strings
var_dump(\SimdUtf\validate_ascii("Hello, 世界!")); // UTF-8 characters
var_dump(\SimdUtf\validate_ascii("🌍")); // Emoji
var_dump(\SimdUtf\validate_ascii("\x80")); // High bit set
var_dump(\SimdUtf\validate_ascii("\xFF")); // All bits set

// Test ASCII validation with detailed error information
$result = \SimdUtf\validate_ascii_with_errors("Hello, world!");
var_dump($result);

$result = \SimdUtf\validate_ascii_with_errors("Hello, 世界!");
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
  int(13)
}
array(3) {
  ["valid"]=>
  bool(false)
  ["count"]=>
  int(7)
  ["error"]=>
  string(25) "Non-ASCII character found"
}
