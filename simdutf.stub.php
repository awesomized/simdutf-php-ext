<?php

/**
 * @generate-class-entries
 * @undocumentable
 */

namespace SimdUtf {

    // validation
    function validate_utf8(string $string): bool {}
    function validate_ascii(string $string): bool {}
    function validate_utf16(string $string): bool {}
    function validate_utf16be(string $string): bool {}
    function validate_utf16le(string $string): bool {}
    function validate_utf32(string $string): bool {}

    // validation with errors
    function validate_utf8_with_errors(string $string): array {}
    function validate_ascii_with_errors(string $string): array {}
    function validate_utf16_with_errors(string $string): array {}
    function validate_utf16be_with_errors(string $string): array {}
    function validate_utf16le_with_errors(string $string): array {}
    function validate_utf32_with_errors(string $string): array {}

    // count
    function count_utf8(string $string): int {}
    function count_utf16(string $string): int {}
    function count_utf16be(string $string): int {}
    function count_utf16le(string $string): int {}

    // utf8 length
    function utf8_length_from_utf16(string $string): int {}
    function utf8_length_from_utf16be(string $string): int {}
    function utf8_length_from_utf16le(string $string): int {}
    function utf8_length_from_utf32(string $string): int {}
    function utf8_length_from_latin1(string $string): int {}

    // uft16 length
    function utf16_length_from_utf8(string $string): int {}
    function utf16_length_from_utf32(string $string): int {}
    function utf16_length_from_latin1(string $string): int {}

    // utf32 length
    function utf32_length_from_utf8(string $string): int {}
    function utf32_length_from_utf16(string $string): int {}
    function utf32_length_from_utf16be(string $string): int {}
    function utf32_length_from_utf16le(string $string): int {}

    // latin1 length
    function latin1_length_from_utf8(string $string): int {}
    function latin1_length_from_utf16(string $string): int {}
    function latin1_length_from_utf32(string $string): int {}

    // convert utf8
    function convert_utf8_to_latin1(string $string): string {}
    function convert_utf8_to_utf16(string $string): string {}
    function convert_utf8_to_utf16be(string $string): string {}
    function convert_utf8_to_utf16le(string $string): string {}
    function convert_utf8_to_utf32(string $string): string {}

    // convert utf16
    function convert_utf16_to_utf8(string $string): string {}
    function convert_utf16_to_latin1(string $string): string {}
    function convert_utf16_to_utf32(string $string): string {}


    // convert utf16be
    function convert_utf16be_to_utf8(string $string): string {}
    function convert_utf16be_to_utf32(string $string): string {}
    function convert_utf16be_to_latin1(string $string): string {}

    // convert utf16le
    function convert_utf16le_to_utf8(string $string): string {}
    function convert_utf16le_to_utf32(string $string): string {}
    function convert_utf16le_to_latin1(string $string): string {}


    // convert utf32
    function convert_utf32_to_utf8(string $string): string {}
    function convert_utf32_to_utf16(string $string): string {}
    function convert_utf32_to_utf16le(string $string): string {}
    function convert_utf32_to_utf16be(string $string): string {}
    function convert_utf32_to_latin1(string $string): string {}

    // convert latin1
    function convert_latin1_to_utf8(string $string): string {}
    function convert_latin1_to_utf16(string $string): string {}
    function convert_latin1_to_utf16le(string $string): string {}
    function convert_latin1_to_utf16be(string $string): string {}
    function convert_latin1_to_utf32(string $string): string {}

    // convert utf8 with errors
    function convert_utf8_to_utf16_with_errors(string $string): array {}
    function convert_utf8_to_utf16be_with_errors(string $string): array {}
    function convert_utf8_to_utf16le_with_errors(string $string): array {}
    function convert_utf8_to_utf32_with_errors(string $string): array {}
    function convert_utf8_to_latin1_with_errors(string $string): array {}

    // convert utf16 with errors
    function convert_utf16_to_utf8_with_errors(string $string): array {}
    function convert_utf16_to_utf32_with_errors(string $string): array {}
    function convert_utf16_to_latin1_with_errors(string $string): array {}

    // convert utf16le with errors
    function convert_utf16le_to_utf8_with_errors(string $string): array {}
    function convert_utf16le_to_latin1_with_errors(string $string): array {}
    function convert_utf16le_to_utf32_with_errors(string $string): array {}

    // convert utf16be with errors
    function convert_utf16be_to_utf8_with_errors(string $string): array {}
    function convert_utf16be_to_utf32_with_errors(string $string): array {}
    function convert_utf16be_to_latin1_with_errors(string $string): array {}

    // convert utf32 with errors
    function convert_utf32_to_utf8_with_errors(string $string): array {}
    function convert_utf32_to_utf16_with_errors(string $string): array {}
    function convert_utf32_to_utf16be_with_errors(string $string): array {}
    function convert_utf32_to_utf16le_with_errors(string $string): array {}
    function convert_utf32_to_latin1_with_errors(string $string): array {}

    // convert valid utf8
    function convert_valid_utf8_to_latin1(string $string): string {}
    function convert_valid_utf8_to_utf16(string $string): string {}
    function convert_valid_utf8_to_utf16le(string $string): string {}
    function convert_valid_utf8_to_utf16be(string $string): string {}
    function convert_valid_utf8_to_utf32(string $string): string {}

    // convert valid utf16
    function convert_valid_utf16_to_utf8(string $string): string {}
    function convert_valid_utf16_to_latin1(string $string): string {}
    function convert_valid_utf16_to_utf32(string $string): string {}

    // convert valid utf16le
    function convert_valid_utf16le_to_utf8(string $string): string {}
    function convert_valid_utf16le_to_utf32(string $string): string {}
    function convert_valid_utf16le_to_latin1(string $string): string {}

    // convert valid utf16be
    function convert_valid_utf16be_to_utf8(string $string): string {}
    function convert_valid_utf16be_to_utf32(string $string): string {}
    function convert_valid_utf16be_to_latin1(string $string): string {}

    // convert valid utf32
    function convert_valid_utf32_to_latin1(string $string): string {}
    function convert_valid_utf32_to_utf8(string $string): string {}
    function convert_valid_utf32_to_utf16(string $string): string {}
    function convert_valid_utf32_to_utf16be(string $string): string {}
    function convert_valid_utf32_to_utf16le(string $string): string {}

    // change endianness
    function change_endianness_utf16(string $string, int $length): string {}

    // trim
    function trim_partial_utf8(string $string, int $length): string {}
    function trim_partial_utf16be(string $string, int $length): string {}
    function trim_partial_utf16le(string $string, int $length): string {}
    function trim_partial_utf16(string $string, int $length): string {}

    // detect encodings
    function autodetect_encoding(string $string): int {}
    function detect_encodings(string $string): int {}

    // base64
    function binary_to_base64(string $string): string {}
    function base64_to_binary(string $string): string {}
    function base64_to_binary_safe(string $string): string {}

}
