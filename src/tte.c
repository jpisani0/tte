/**
 * @file tte.c
 * @author J. Pisani (jgp9201@gmail.com)
 * @brief Main driver for tte
 * @version 0.1
 * @date 2025-01-22
 */

#include "tte.h"

int main(int argc, char** argv)
{
    const char* functionName = "tte():";
    char c = 0;
    termios originalTerminal; // Original terminal attributes

    // Put terminal into raw mode
    enableRawMode(&originalTerminal);

    // Read the input to the terminal as it comes in
    while(read(STDIN_FILENO, &c, 1) == 1)
    {
        printf("You entered: %c" NEWLINE, c);
        fflush(stdout); // Immediate output to avoid buffering issues

        if(c == 'q' || c == 'Q')
        {
            printf("Exiting..." NEWLINE);
            break;
        }
    }

    disableRawMode(&originalTerminal);

    return 0;
}
