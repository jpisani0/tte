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
        // Exit if q is entered (just for testing for now)
        if(c == 'q' || c == 'Q')
        {
            printf("Exiting..." NEWLINE);
            fflush(stdout); // Immediate output to avoid buffering issues
            break;
        }
        else if(c == ESCAPE_CHARACTER)
        {
            // If the escape sequence is caught, check which control sequence it is
            char controlSequence[2] = "";

            read(STDIN_FILENO, &controlSequence[0], 1);
            read(STDIN_FILENO, &controlSequence[1], 1);

            if(controlSequence[0] == CONTROL_SEQUENCE_INTRODUCER)
            {
                if(controlSequence[1] == UP_ARROW)
                {
                    printf("Up Arrow" NEWLINE);
                }
                else if(controlSequence[1] == DOWN_ARROW)
                {
                    printf("Down Arrow" NEWLINE);
                }
                else if(controlSequence[1] == RIGHT_ARROW)
                {
                    printf("Right Arrow" NEWLINE);
                }
                else if(controlSequence[1] == LEFT_ARROW)
                {
                    printf("Left Arrow" NEWLINE);
                }
            }
        }
        else
        {
            // Standard character
            printf("%c" NEWLINE, c);
        }

        fflush(stdout); // Immediate output to avoid buffering issues
    }

    disableRawMode(&originalTerminal);

    return 0;
}
