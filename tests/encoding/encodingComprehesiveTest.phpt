--TEST--
Comprehensive encoding detection test
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not available');
?>
--FILE--
<?php
// Helper function to describe detected encoding
function describe_encoding($str, $desc) {
    $encoding = \SimdUtf\autodetect_encoding($str);
    echo "$desc detected as: ";
    switch($encoding) {
        case SIMDUTF_ENCODING_UNSPECIFIED: echo "UNKNOWN"; break;
        case SIMDUTF_ENCODING_UTF8: echo "UTF8"; break;
        case SIMDUTF_ENCODING_UTF16_LE: echo "UTF16_LE"; break;
        case SIMDUTF_ENCODING_UTF16_BE: echo "UTF16_BE"; break;
        case SIMDUTF_ENCODING_UTF32_LE: echo "UTF32_LE"; break;
        case SIMDUTF_ENCODING_UTF32_BE: echo "UTF32_BE"; break;
        default: echo "UNEXPECTED($encoding)";
    }
    echo "\n";
}

// Test empty string
describe_encoding('', "Empty string");

// Test ASCII/UTF-8
describe_encoding('Hello World', "ASCII string");
describe_encoding('Hello 世界', "UTF-8 string with CJK");

// Test UTF-32LE
$utf32le = "\xFF\xFE\x00\x00\x37\x04\x01\x00";
describe_encoding($utf32le, "UTF-32LE with BOM");

// Test UTF-32BE
$utf32be = "\x00\x00\xFE\xFF\x00\x01\x04\x37";
describe_encoding($utf32be, "UTF-32BE with BOM");

// Test longer content
$utf32le_long = "\xFF\xFE\x00\x00" . str_repeat("\x37\x04\x01\x00", 100);
describe_encoding($utf32le_long, "Long UTF-32LE content");

$utf32be_long = "\x00\x00\xFE\xFF" . str_repeat("\x00\x01\x04\x37", 100);
describe_encoding($utf32be_long, "Long UTF-32BE content");
?>
--EXPECT--
Empty string detected as: UNKNOWN
ASCII string detected as: UTF8
UTF-8 string with CJK detected as: UTF8
UTF-32LE with BOM detected as: UTF32_LE
UTF-32BE with BOM detected as: UTF32_BE
Long UTF-32LE content detected as: UTF32_LE
Long UTF-32BE content detected as: UTF32_BE
