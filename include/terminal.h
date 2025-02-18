/**
 * @file terminal.h
 * @author J. Pisani (jgp9201@gmail.com)
 * @brief Contains functions for getting input from, sending output to, and manipulating the terminal
 * @version 0.1
 * @date 2025-01-26
 */

#ifndef _TTE_TERMINAL_H
#define _TTE_TERMINAL_H

#include <termios.h>
#include <unistd.h>

typedef struct termios termios;

/* Keyboard Codes - found using 'showkey -a' in bash */

#define ESC_CODE 27 // Decimal value of the escape control code. Precedes all escape sequences. HEX: 0x1b, CHAR: '^['. Can also use '\e' in formatted strings
#define CONTROL_SEQUENCE_INTRODUCER 91 // Character for introducing a control sequence. HEX: 0x5b, CHAR: '['

#define ESC_SEQUENCE "\x1b" // Escape sequence for formatted strings. Can also use '\e'.
#define NEWLINE "\r\n" // move cursor to beginning of next line

// Terminal manipulation string defines for use in printf()
#define CLEAR_SCREEN (ESC_SEQUENCE "[2J") // Clears the screen
#define OPEN_ALTERNATE_SCREEN (ESC_SEQUENCE "[?1049h") // Opens an alternate screen for the program
#define CLOSE_ALTERNATE_SCREEN (ESC_SEQUENCE "[?1049l") // Closes the alternate screen and returns to the original one

// Arrow Keys
#define UP_ARROW    65 // Up Arrow command character for a control sequence.    HEX: 0x41, CHAR: 'A', FULL COMMAND SEQUENCE: "^[[A"
#define DOWN_ARROW  66 // Down Arrow command character for a control sequence.  HEX: 0x42, CHAR: 'B', FULL COMMAND SEQUENCE: "^[[B"
#define RIGHT_ARROW 67 // Right Arrow command character for a control sequence. HEX: 0x43, CHAR: 'C', FULL COMMAND SEQUENCE: "^[[C"
#define LEFT_ARROW  68 // Left Arrow command character for a control sequence.  HEX: 0x44, CHAR: 'D', FULL COMMAND SEQUENCE: "^[[D"

// TTE Specific definitions
#define EXIT_COMMAND  4   // Exit the TTE. Ctrl+D, HEX: 0x04
#define CONFIRM_LOWER 121 // Confirmation from the user to go through with a requested action. HEX: 0x79, CHAR: 'y'
#define CONFIRM_UPPER 89  // Confirmation from the user to go through with a requested action. HEX: 0x59, CHAR: 'Y'
#define SCREEN_TOP 1 // For use in moveCursorAbsolute(SCREEN_TOP, X) to move the cursor to the top of the screen
#define SCREEN_LEFT 1 // For use in moveCursorAbsolute(X, SCREEN_LEFT) to move the cursor to the left of the screen

void enableRawMode(termios *originalTerminal);
void disableRawMode(termios *originalTerminal);
void openAlternateScreen(void);
void closeAlternateScreen(void);
void moveCursorRelative(int distance, char direction);
void moveCursorAbsolute(int col, int row);

#endif
