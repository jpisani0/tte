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

#include "terminal.h"

#define NEWLINE "\r\n" // move cursor to beginning of next line

#define ESCAPE_DECIMAL 27 // decimal value of the escape control code
#define ESCAPE_STRING "\x1b"  // precedes all escape sequences

// Arrow Keys
#define UP_ARROW    (ESCAPE "[A")
#define DOWN_ARROW  (ESCAPE "[B")
#define RIGHT_ARROW (ESCAPE "[C")
#define LEFT_ARROW  (ESCAPE "[D")

#endif