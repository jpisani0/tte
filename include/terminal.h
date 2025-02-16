/**
 * @file terminal.h
 * @author J. Pisani (jgp9201@gmail.com)
 * @brief Contains functions for manipulating the terminal
 * @version 0.1
 * @date 2025-01-26
 */

#ifndef _TTE_TERMINAL_H
#define _TTE_TERMINAL_H

#include <termios.h>
#include <unistd.h>

#define clearScreen() printf("\e[1;1H]\e[2J") // Clears the terminal and places cursor in top right corner

typedef struct termios termios;

void enableRawMode(void);
void disableRawMode(void);

#endif
