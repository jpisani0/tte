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
        if(c == EXIT_COMMAND)
        {
            printf("Are you sure you want to exit? (y/N) ");
            fflush(stdout);

            char answer = 0;
            read(STDIN_FILENO, &answer, 1);

            if(answer == CONFIRM_LOWER || answer == CONFIRM_UPPER)
            {
                printf(NEWLINE "Exiting..." NEWLINE);
                fflush(stdout); // Immediate output to avoid buffering issues
                break;
            }
            else
            {
                printf(NEWLINE);
                fflush(stdout);
            }
        }
        else if(c == ESCAPE_CHARACTER)
        {
            // If the escape sequence is caught, check which control sequence it is
            char escapeSequence[2] = "";

            read(STDIN_FILENO, &escapeSequence[0], 1);
            read(STDIN_FILENO, &escapeSequence[1], 1);

            if(escapeSequence[0] == CONTROL_SEQUENCE_INTRODUCER)
            {
                if(escapeSequence[1] == UP_ARROW)
                {
                    moveCursorRelative(1, UP_ARROW);
                }
                else if(escapeSequence[1] == DOWN_ARROW)
                {
                    moveCursorRelative(1, DOWN_ARROW);
                }
                else if(escapeSequence[1] == RIGHT_ARROW)
                {
                    moveCursorRelative(1, RIGHT_ARROW);
                }
                else if(escapeSequence[1] == LEFT_ARROW)
                {
                    moveCursorRelative(1, LEFT_ARROW);
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

    // Disable raw mode by setting the original terminal attributes
    disableRawMode(&originalTerminal);

    return 0;
}
