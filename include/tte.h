/**
 * @file tte.h
 * @author J. Pisani (jgp9201@gmail.com)
 * @brief Contains functionality for the main program
 * @version 0.1
 * @date 2025-01-28
 */

#ifndef _TERMINAL_TEXT_EDITOR_H
#define _TERMINAL_TEXT_EDITOR_H

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#include "terminal.h"

#define NEWLINE "\r\n" // move cursor to beginning of next line

/* Keyboard Codes - found using 'showkey -a' in bash */

#define ESCAPE_CHARACTER 27 // Decimal value of the escape control code. Precedes all escape sequences. HEX: 0x1b, CHAR: '^[' 
#define CONTROL_SEQUENCE_INTRODUCER 91 // Character for introducing a control sequence. HEX: 0x5b, CHAR: '['

#define EXIT_COMMAND  4   // Exit the TTTE. Ctrl+D, HEX: 0x04
#define CONFIRM_LOWER 121 // Confirmation from the user to go through with a requested action. HEX: 0x79, CHAR: 'y'
#define CONFIRM_UPPER 89  // Confirmation from the user to go through with a requested action. HEX: 0x59, CHAR: 'Y'

// Arrow Keys
#define UP_ARROW    65 // Up Arrow command character for a control sequence.    HEX: 0x41, CHAR: 'A', FULL COMMAND SEQUENCE: "^[[A"
#define DOWN_ARROW  66 // Down Arrow command character for a control sequence.  HEX: 0x42, CHAR: 'B', FULL COMMAND SEQUENCE: "^[[B"
#define RIGHT_ARROW 67 // Right Arrow command character for a control sequence. HEX: 0x43, CHAR: 'C', FULL COMMAND SEQUENCE: "^[[C"
#define LEFT_ARROW  68 // Left Arrow command character for a control sequence.  HEX: 0x44, CHAR: 'D', FULL COMMAND SEQUENCE: "^[[D"

#endif