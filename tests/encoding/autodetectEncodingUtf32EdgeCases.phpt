--TEST--
Edge cases for UTF-32 detection
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not available');
?>
--FILE--
<?php
// Test UTF-32LE BOM alone
var_dump(\SimdUtf\autodetect_encoding("\xFF\xFE\x00\x00"));

// Test UTF-32BE BOM alone
var_dump(\SimdUtf\autodetect_encoding("\x00\x00\xFE\xFF"));

// Test UTF-32LE content without BOM (should not detect as UTF-32)
$content_no_bom = "\x37\x04\x01\x00\x38\x04\x01\x00\x39\x04\x01\x00";
var_dump(\SimdUtf\autodetect_encoding($content_no_bom));

// Test mismatched BOM (LE BOM with BE content)
$mismatch_le = "\xFF\xFE\x00\x00" .  // LE BOM
               "\x00\x01\x04\x37";    // BE content
var_dump(\SimdUtf\autodetect_encoding($mismatch_le));

// Test mismatched BOM (BE BOM with LE content)
$mismatch_be = "\x00\x00\xFE\xFF" .  // BE BOM
               "\x37\x04\x01\x00";    // LE content
var_dump(\SimdUtf\autodetect_encoding($mismatch_be));
?>
--EXPECTF--
int(8)
int(16)
int(%d)
int(8)
int(16)
