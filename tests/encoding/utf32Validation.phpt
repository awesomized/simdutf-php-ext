--TEST--
Basic UTF-32 detection tests with BOMs
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
        case SIMDUTF_ENCODING_UNSPECIFIED: echo "UNSPECIFIED"; break;
        case SIMDUTF_ENCODING_UTF8: echo "UTF8"; break;
        case SIMDUTF_ENCODING_UTF16_LE: echo "UTF16_LE"; break;
        case SIMDUTF_ENCODING_UTF16_BE: echo "UTF16_BE"; break;
        case SIMDUTF_ENCODING_UTF32_LE: echo "UTF32_LE"; break;
        case SIMDUTF_ENCODING_UTF32_BE: echo "UTF32_BE"; break;
        default: echo "UNEXPECTED($encoding)";
    }
    echo " ($encoding)\n";
}

// Test empty string
describe_encoding('', "Empty string");

// Test UTF-32LE with BOM
$utf32le = "\xFF\xFE\x00\x00\x37\x04\x01\x00";
describe_encoding($utf32le, "UTF-32LE with BOM");

// Test UTF-32BE with BOM
$utf32be = "\x00\x00\xFE\xFF\x00\x01\x04\x37";
describe_encoding($utf32be, "UTF-32BE with BOM");

// Test UTF-8
$utf8 = "Hello 世界";
describe_encoding($utf8, "UTF-8 string");

// Test UTF-16LE with BOM
$utf16le = "\xFF\xFE\x48\x00\x65\x00\x6C\x00\x6C\x00\x6F\x00";
describe_encoding($utf16le, "UTF-16LE with BOM");

// Test UTF-16BE with BOM
$utf16be = "\xFE\xFF\x00\x48\x00\x65\x00\x6C\x00\x6C\x00\x6F";
describe_encoding($utf16be, "UTF-16BE with BOM");
?>
--EXPECT--
Empty string detected as: UNSPECIFIED (0)
UTF-32LE with BOM detected as: UTF32_LE (8)
UTF-32BE with BOM detected as: UTF32_BE (16)
UTF-8 string detected as: UTF8 (1)
UTF-16LE with BOM detected as: UTF16_LE (2)
UTF-16BE with BOM detected as: UTF16_BE (4)
