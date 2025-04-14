--TEST--
SIMDUTF count functions test suite
--EXTENSIONS--
simdutf
--FILE--
<?php

// UTF-8 Tests
echo "=== UTF-8 Tests ===\n";

// Basic ASCII string
var_dump(\SimdUtf\count_utf8("Hello World"));

// Empty string
var_dump(\SimdUtf\count_utf8(""));

// Mixed ASCII and Unicode
var_dump(\SimdUtf\count_utf8("Hello 世界"));

// Multi-byte characters
var_dump(\SimdUtf\count_utf8("こんにちは"));

// Emojis (each emoji is typically 4 bytes in UTF-8)
var_dump(\SimdUtf\count_utf8("🌟✨🌙"));

// Long string with mixed characters
var_dump(\SimdUtf\count_utf8(str_repeat("Hello世界", 1000)));

// Error case - NULL byte
try {
    \SimdUtf\count_utf8("\0");
} catch (Exception $e) {
    echo "Exception caught for NULL byte\n";
}

echo "\n=== UTF-16 Tests ===\n";

// Basic ASCII string
var_dump(\SimdUtf\count_utf16("Hello World"));

// Empty string
var_dump(\SimdUtf\count_utf16(""));

// Mixed ASCII and Unicode
var_dump(\SimdUtf\count_utf16("Hello 世界"));

// Multi-byte characters
var_dump(\SimdUtf\count_utf16("こんにちは"));

// Emojis
var_dump(\SimdUtf\count_utf16("🌟✨🌙"));

echo "\n=== UTF-16LE Tests ===\n";

// Basic ASCII string
var_dump(\SimdUtf\count_utf16le("Hello World"));

// Empty string
var_dump(\SimdUtf\count_utf16le(""));

// Mixed ASCII and Unicode
var_dump(\SimdUtf\count_utf16le("Hello 世界"));

// Multi-byte characters
var_dump(\SimdUtf\count_utf16le("こんにちは"));

// Emojis
var_dump(\SimdUtf\count_utf16le("🌟✨🌙"));

echo "\n=== UTF-16BE Tests ===\n";

// Basic ASCII string
var_dump(\SimdUtf\count_utf16be("Hello World"));

// Empty string
var_dump(\SimdUtf\count_utf16be(""));

// Mixed ASCII and Unicode
var_dump(\SimdUtf\count_utf16be("Hello 世界"));

// Multi-byte characters
var_dump(\SimdUtf\count_utf16be("こんにちは"));

// Emojis
var_dump(\SimdUtf\count_utf16be("🌟✨🌙"));

// Test invalid UTF-8 sequences
$invalid_utf8 = "\xFF\xFF\xFF\xFF";
try {
    \SimdUtf\count_utf16($invalid_utf8);
} catch (Exception $e) {
    echo "Exception caught for invalid UTF-8\n";
}

try {
    \SimdUtf\count_utf16le($invalid_utf8);
} catch (Exception $e) {
    echo "Exception caught for invalid UTF-8\n";
}

try {
    \SimdUtf\count_utf16be($invalid_utf8);
} catch (Exception $e) {
    echo "Exception caught for invalid UTF-8\n";
}

?>
--EXPECT--
=== UTF-8 Tests ===
int(11)
int(0)
int(8)
int(5)
int(3)
int(7000)

=== UTF-16 Tests ===
int(11)
int(0)
int(8)
int(5)
int(3)

=== UTF-16LE Tests ===
int(11)
int(0)
int(8)
int(5)
int(3)

=== UTF-16BE Tests ===
int(11)
int(0)
int(8)
int(5)
int(5)
Exception caught for invalid UTF-8
Exception caught for invalid UTF-8
Exception caught for invalid UTF-8
