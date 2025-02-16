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

#define TERMINAL_ERROR -1

/**
 * @brief Save original terminal attributes and place the terminal into "raw" mode
 * 
 * @param originalTerminal - the original terminal attributes to be saved before entering "raw" mode
 */
void enableRawMode(termios *originalTerminal)
{
    const char* functionName = "enableRawMode():";
    termios rawTerminal;

    // REVIEW: should we reset the terminal before exiting if there was an issue when setting attr?
    // Save the original terminal attributes
    if(tcgetattr(STDIN_FILENO, originalTerminal) == TERMINAL_ERROR)
    {
        perror("enableRawMode(): failed to get original terminal attributes\n");
        exit(EXIT_FAILURE);
    }

    // Set the new attributes for the raw terminal
    rawTerminal.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);          // local flags
    rawTerminal.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON); // input flags
    rawTerminal.c_oflag &= ~(OPOST);                                  // output flags
    rawTerminal.c_cflag |= CS8;                                       // control flags

    // Set terminal so that read() wait for at least 1 byte before returning
    rawTerminal.c_cc[VMIN] = 1;
    rawTerminal.c_cc[VTIME] = 0;

    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &rawTerminal) == TERMINAL_ERROR)
    {
        perror("enableRawMode(): failed to set terminal in raw mode\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Take the terminal out of "raw" mode by restoring original attributes
 * 
 * @param originalTerminal - the original terminal attributes to be restored before exiting
 */
void disableRawMode(termios *originalTerminal)
{
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, originalTerminal) == TERMINAL_ERROR)
    {
        perror("disableRawMode(): could not restore original terminal attributes\n");
        exit(EXIT_FAILURE);
    }
}
