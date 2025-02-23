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

int lineIndex = 0;


/**
 * @brief Load a line from the file into memory
 * 
 * @param prev - the previous line in the list
 * @param next - the next line in the list
 * @return Line* 
 */
Line* loadLine(Line *prev, Line* next)
{
    Line *line = (Line *)calloc(1, sizeof(Line));
    snprintf(line->data, MAX_LINE_SIZE, "Line %d, rows %d, cols %d\r", lineIndex + 1, textEditor->terminalRows, textEditor->terminalCols);
    line->prev = prev;
    line->next = next;
    line->lineNumber = 0; // TODO
    line->lineSize = strlen(line->data);
}

/**
 * @brief Display a line to the terminal
 * 
 * @param line 
 */
void displayLine(Line *line)
{
    printf("%s", line->data);
}

/**
 * @brief Display a file to the terminal 
 * 
 */
void displayFile(void)
{
    textEditor = (TextEditor *)calloc(1, sizeof(TextEditor));

    getTerminalSize(&textEditor->terminalRows, &textEditor->terminalCols);

    for(lineIndex = 0; lineIndex < textEditor->terminalRows; lineIndex++)
    {
        Line* line = loadLine(NULL, NULL);
        displayLine(line);
        moveCursorRelative(1, DOWN_ARROW);

        free(line);
    }

    free(textEditor);

    printf("Done!");
}
