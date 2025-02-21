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
#include <sys/ioctl.h>

#include "keycodes.h"

typedef struct termios termios;

// Terminal manipulation string defines for use in printf()
#define CLEAR_SCREEN (ESC_SEQUENCE "[2J")               // Clears the screen
#define OPEN_ALTERNATE_SCREEN (ESC_SEQUENCE "[?1049h")  // Opens an alternate screen for the program
#define CLOSE_ALTERNATE_SCREEN (ESC_SEQUENCE "[?1049l") // Closes the alternate screen and returns to the original one

// Cursor movement defines for use with moveCursorAbsolute()
#define SCREEN_TOP    1   // moveCursorAbsolute(SCREEN_TOP, X) to move the cursor to the top of the screen
#define SCREEN_LEFT   1   // moveCursorAbsolute(X, SCREEN_LEFT) to move the cursor to the left of the screen

// Default window size to assume for the terminal
#define DEFAULT_ROW_SIZE 24
#define DEFAULT_COL_SIZE 80

typedef struct winsize winsize;

void enableRawMode(termios *originalTerminal);
void disableRawMode(termios *originalTerminal);
void openAlternateScreen(void);
void closeAlternateScreen(void);
void moveCursorRelative(int distance, char direction);
void moveCursorAbsolute(int col, int row);
void getTerminalSize(int *terminalRows, int *terminalCols);

#endif
