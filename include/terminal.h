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

#define clearScreen() printf("\e[1;1H]\e[2J") // Clears the terminal and places cursor in top right corner

typedef struct termios termios;

#define ESCAPE_STRING "\x1b" // Escape sequence for formatted strings

// Arrow Keys
#define UP_ARROW    65 // Up Arrow command character for a control sequence.    HEX: 0x41, CHAR: 'A', FULL COMMAND SEQUENCE: "^[[A"
#define DOWN_ARROW  66 // Down Arrow command character for a control sequence.  HEX: 0x42, CHAR: 'B', FULL COMMAND SEQUENCE: "^[[B"
#define RIGHT_ARROW 67 // Right Arrow command character for a control sequence. HEX: 0x43, CHAR: 'C', FULL COMMAND SEQUENCE: "^[[C"
#define LEFT_ARROW  68 // Left Arrow command character for a control sequence.  HEX: 0x44, CHAR: 'D', FULL COMMAND SEQUENCE: "^[[D"

void enableRawMode(termios *originalTerminal);
void disableRawMode(termios *originalTerminal);

void moveCursorRelative(int distance, char direction);
void moveCursorAbsolute(int col, int row);

#endif
