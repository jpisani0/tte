/**
 * @file terminal.c
 * @author J. Pisani (jgp9201@gmail.com)
 * @brief Functions for manipulating the temrinal
 * @version 0.1
 * @date 2025-01-25
 */

#include <stdio.h>
#include <stdlib.h>

#include "terminal.h"

#define LOCAL_FLAG_ATTS (ECHO | ICANON | ISIG | IEXTEN)
#define INPUT_FLAG_ATTS (BRKINT | ICRNL | INPCK | ISTRIP | IXON)
#define OUTPUT_FLAG_ATTS (OPOST)
#define CONTROL_FLAG_ATTS (CS8)

/**
 * @brief Put the terminal into raw mode
 * 
 * @param rawTerminal 
 */
void enableRawMode(void)
{
    termios rawTerminal;

    rawTerminal.c_lflag &= ~(LOCAL_FLAG_ATTS);
    rawTerminal.c_iflag &= ~(INPUT_FLAG_ATTS);
    rawTerminal.c_oflag &= ~(OUTPUT_FLAG_ATTS);
    rawTerminal.c_cflag |= (CONTROL_FLAG_ATTS);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &rawTerminal);
}

void disableRawMode(void)
{
    termios originalTerminal;

    originalTerminal.c_lflag |= (LOCAL_FLAG_ATTS);
    originalTerminal.c_iflag |= (INPUT_FLAG_ATTS);
    originalTerminal.c_oflag |= (OUTPUT_FLAG_ATTS);
    originalTerminal.c_cflag &= ~(CONTROL_FLAG_ATTS);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &originalTerminal);
}
