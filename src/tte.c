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

    // REVIEW: should stuff like this, being a simple printf() be its own function for clarity? i.e. clearScreen() { printf(CLEAR_SCREEN); fflush(stdout)}
    // REVIEW: or should there be a rawPrint() function that prints and flushes right after to avoid having to write both lines everytime?
    // Clear the terminal screen
    // printf(CLEAR_SCREEN);
    // fflush(stdout);

    openAlternateScreen();
    moveCursorAbsolute(SCREEN_TOP, SCREEN_LEFT); // Move the cursor to the top left of the screen

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
        else if(c == ESC_CODE)
        {
            // If the escape sequence is caught, check which control sequence it is
            char escapeSequence[2] = "";

            read(STDIN_FILENO, &escapeSequence[0], 1);
            read(STDIN_FILENO, &escapeSequence[1], 1);

            if(escapeSequence[0] == CONTROL_SEQUENCE_INTRODUCER)
            {
                // REVIEW: this could probably be just passing the value of escapeSequence[1] through, as long as the escape sequences we are checking are arrow keys (doubtful)
                switch(escapeSequence[1])
                {
                    case UP_ARROW:
                    case DOWN_ARROW:
                    case RIGHT_ARROW:
                    case LEFT_ARROW:
                        moveCursorRelative(1, escapeSequence[1]);
                        break;

                    default:
                        // TODO: proper handling of default case
                        break;
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

    closeAlternateScreen();

    // Disable raw mode by setting the original terminal attributes
    disableRawMode(&originalTerminal);

    return 0;
}
