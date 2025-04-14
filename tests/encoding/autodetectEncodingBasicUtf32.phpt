--TEST--
Basic UTF-32 detection tests with BOMs
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not available');
?>
--FILE--
<?php
// Test empty string
var_dump(\SimdUtf\autodetect_encoding(''));

// UTF-32LE BOM + content (U+10437, U+10438, U+10439)
$utf32le = "\xFF\xFE\x00\x00" .      // BOM
          "\x37\x04\x01\x00" .       // U+10437
          "\x38\x04\x01\x00" .       // U+10438
          "\x39\x04\x01\x00";        // U+10439
var_dump(\SimdUtf\autodetect_encoding($utf32le));

// UTF-32BE BOM + content
$utf32be = "\x00\x00\xFE\xFF" .      // BOM
          "\x00\x01\x04\x37" .       // U+10437
          "\x00\x01\x04\x38" .       // U+10438
          "\x00\x01\x04\x39";        // U+10439
var_dump(\SimdUtf\autodetect_encoding($utf32be));

// Basic UTF-8 (no BOM needed)
$utf8_string = "Hello 世界";
var_dump(\SimdUtf\autodetect_encoding($utf8_string));
?>
--EXPECT--
int(0)
int(8)
int(16)
int(1)
