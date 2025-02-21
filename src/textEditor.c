/**
 * @file textEditor.c
 * @author J. Pisani (jgp9201@gmail.com)
 * @brief Functions for loading and editing text files
 * @version 0.1
 * @date 2025-02-18
 */

#include <stdio.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdlib.h>

#include "textEditor.h"
#include "terminal.h"

FILE *file = NULL;
TextEditor *textEditor = NULL;

void displayLine(Line* line);

/**
 * @brief Load and display the chosen file. If no file is provided or 
 *        the provided file does not exist yet, opens an empty text editor
 * 
 * @param filename 
 */
void loadFile(char filename[MAX_FILE_NAME_SIZE])
{
    // TODO: Should check if no filename was provided (filename == "")
    file = fopen(filename, "a"); // Open the file in append mode

    if(file == NULL)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    textEditor = (TextEditor *)malloc(sizeof(textEditor)); // Allocate memory for the textEditor struct

    if(textEditor == NULL)
    {
        perror("Failed to setup text editor");
        exit(EXIT_FAILURE);
    }

    // Get the size of the terminal window
    getTerminalSize(&textEditor->terminalRows, &textEditor->terminalCols);

    for(int lineIndex = 0; lineIndex < textEditor->terminalRows; lineIndex++)
    {
        // Doing this without the moveCursorRelative() causes Line 1 to not be printed and the last line to stay blank
        // printf("Line %d" NEWLINE, lineIndex + 1);
        
        // This prints properly
        printf("Line %d\r", lineIndex + 1);
        moveCursorRelative(1, DOWN_ARROW);
    }

    // Move cursor to top left after displaying lines
    moveCursorAbsolute(SCREEN_TOP, SCREEN_LEFT);
}

void loadNextLine(Line *currentLine)
{
    Line *nextLine = (Line *)malloc(sizeof(Line));

    fgets(nextLine->data, MAX_LINE_SIZE, file);
    nextLine->prev = currentLine;
    nextLine->next = NULL;
    nextLine->lineNumber = (currentLine == NULL) ? 0 : currentLine->lineNumber + 1;
    nextLine->lineSize = strlen(nextLine->data);
}

void unloadNextLine(Line *currentLine)
{
    free(currentLine->next);
    currentLine->next = NULL;
}

void loadPreviousLine(Line *currentLine)
{
    Line* previousLine = (Line *)malloc(sizeof(Line));

    // TODO: need to move index where we are looking in the file back up, prob should track in TextEditor
    fgets(previousLine->data, MAX_LINE_SIZE, file);
    previousLine->prev = NULL;
    previousLine->next = currentLine;
    previousLine->lineNumber = 0;
    previousLine->lineSize = strlen(previousLine->data);
}

void displayLine(Line* line)
{
    printf("%s", line->data);
}
