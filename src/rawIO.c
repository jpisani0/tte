/**
 * @file rawIO.c
 * @author J. Pisani (jgp9201@gmail.com)
 * @brief Functions to handle taking input and sending output to the terminal in "raw" mode
 * @version 0.1
 * @date 2025-02-17
 */

#include <stdio.h>
#include <unistd.h>

#include "rawIO.h"
#include "terminal.h"
#include "keycodes.h"

#define TRUE 0
#define FALSE -1

#define EXIT_COMMAND  4   // Exit the TTE. Ctrl+D, HEX: 0x04
#define CONFIRM_LOWER 121 // Confirmation from the user to go through with a requested action. HEX: 0x79, CHAR: 'y'
#define CONFIRM_UPPER 89  // Confirmation from the user to go through with a requested action. HEX: 0x59, CHAR: 'Y'

char exitPrompt(void);
void handleEscapeSequence(void);


/**
 * @brief Continuously scans for user input when using TTE until they request to exit
 * 
 * @return char 
 */
char scanForInput(void)
{
    char c = 0;
    char exit = FALSE;

    if(read(STDIN_FILENO, &c, 1) == 1)
    {
        // Exit if q is entered (just for testing for now)
        if(c == EXIT_COMMAND)
        {
            exit = exitPrompt();
        }
        else if(c == ESC_CODE)
        {
            handleEscapeSequence();
        }
        else
        {
            // Standard character
            printf("%c" NEWLINE, c);
            fflush(stdout);
        }
    }
    else
    {
        exit = TRUE;
    }

    return exit;
}

// TODO: add functionality to ask the user if they want to save any unsaved changes if they choose yes
/**
 * @brief Prompt for the user to confirm they want to exit tte
 * 
 * @return char 
 */
char exitPrompt(void)
{
    char exit = FALSE;

    printf("Are you sure you want to exit? (y/N) ");
    fflush(stdout);

    char answer = 0;
    read(STDIN_FILENO, &answer, 1);

    if(answer == CONFIRM_LOWER || answer == CONFIRM_UPPER)
    {
        printf(NEWLINE "Exiting..." NEWLINE);
        fflush(stdout); // Immediate output to avoid buffering issues
        exit = TRUE;
    }
    else
    {
        printf(NEWLINE);
        fflush(stdout);
    }

    return exit;
}

// REVIEW: prob can add functions to handle escape sequences in another file, escapeSequences.c
/**
 * @brief When an escape sequence is caught, check which it is and handle accordingly
 * 
 */
void handleEscapeSequence(void)
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
