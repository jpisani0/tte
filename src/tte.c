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
        if(c == 'q' || c == 'Q')
        {
            printf("Exiting..." NEWLINE);
            fflush(stdout); // Immediate output to avoid buffering issues
            break;
        }
        else if(c == ESCAPE_DECIMAL)
        {
            char stuff[2] = "";

            read(STDIN_FILENO, &stuff[0], 1);
            read(STDIN_FILENO, &stuff[1], 1);

            if(stuff[0] == '[')
            {
                if(stuff[1] == 'A')
                {
                    printf("Up Arrow" NEWLINE);
                }
                else if(stuff[1] == 'B')
                {
                    printf("Down Arrow" NEWLINE);
                }
                else if(stuff[1] == 'C')
                {
                    printf("Right Arrow" NEWLINE);
                }
                else if(stuff[1] == 'D')
                {
                    printf("Left Arrow" NEWLINE);
                }
            }
        }
        else
        {
            // Standard character
            printf("You entered: %c" NEWLINE, c);
            fflush(stdout); // Immediate output to avoid buffering issues
        }
    }

    disableRawMode(&originalTerminal);

    return 0;
}
