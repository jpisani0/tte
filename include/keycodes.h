/**
 * @file keycodes.h
 * @author J. Pisani (jgp9201@gmail.com)
 * @brief Contains definitions for common key and sequence codes
 * @version 0.1
 * @date 2025-02-18
 */

#ifndef _KEY_CODES_H
#define _KEY_CODES_H

// Keyboard Codes - found using 'showkey -a' in bash 
#define ESC_CODE 27                    // Decimal value of the escape control code. Precedes all escape sequences. HEX: 0x1b, CHAR: '^['. Can also use '\e' in formatted strings
#define CONTROL_SEQUENCE_INTRODUCER 91 // Character for introducing a control sequence. HEX: 0x5b, CHAR: '['

// Formatted String Sequences
#define ESC_SEQUENCE "\x1b" // Escape sequence for formatted strings. Can also use '\e'.
#define NEWLINE "\r\n"      // move cursor to beginning of next line

// Arrow Keys
#define UP_ARROW    65 // Up Arrow command character for a control sequence.    HEX: 0x41, CHAR: 'A', FULL COMMAND SEQUENCE: "^[[A"
#define DOWN_ARROW  66 // Down Arrow command character for a control sequence.  HEX: 0x42, CHAR: 'B', FULL COMMAND SEQUENCE: "^[[B"
#define RIGHT_ARROW 67 // Right Arrow command character for a control sequence. HEX: 0x43, CHAR: 'C', FULL COMMAND SEQUENCE: "^[[C"
#define LEFT_ARROW  68 // Left Arrow command character for a control sequence.  HEX: 0x44, CHAR: 'D', FULL COMMAND SEQUENCE: "^[[D"

#endif
