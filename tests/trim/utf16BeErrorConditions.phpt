--TEST--
UTF-16BE trim error conditions
--SKIPIF--
<?php
if (!extension_loaded('simdutf')) die('skip simdutf extension not loaded');
?>
--FILE--
<?php
try {
    // Test odd length input
    var_dump(\SimdUtf\trim_partial_utf16be("\x00\x41\x00"));
} catch (Exception $e) {
    echo $e->getMessage(), "\n";
}

try {
    // Test very large odd length
    $large = str_repeat('A', 1025);
    var_dump(\SimdUtf\trim_partial_utf16be($large));
} catch (Exception $e) {
    echo $e->getMessage(), "\n";
}
?>
--EXPECT--
Input length must be even for UTF-16BE
Input length must be even for UTF-16BE
