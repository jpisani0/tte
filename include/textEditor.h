/**
 * @file textEditor.h
 * @author J. Pisani (jgp9201@gmail.com)
 * @brief Contains functions for opening and editing text files
 * @version 0.1
 * @date 2025-02-18
 */

#ifndef _TEXT_EDITOR_H
#define _TEXT_EDITOR_H

// File control defines
#define WRITE  "w"
#define APPEND "a"
#define READ   "r"

// String size defines
#define MAX_FILE_NAME_SIZE 64 // 64 characters // REVIEW: need to find what we can actually support
#define MAX_LINE_SIZE 1024 // Max amount of characters we can read in a line // REVIEW: what is the actual maxa we should put here

// Structure to hold all necessary data in a line
typedef struct Line
{
    char data[MAX_LINE_SIZE]; // The data/string in the line
    struct Line *prev;        // The previous line
    struct Line *next;        // The next line
    int lineNumber;           // The line number in the text editor (vertical position)
    int lineSize;             // The amount of characters in the line (horizontal position)
    int filePosition;         // Position of this line in the file
}Line;

// Structure to hold all necessary data in the text editor
typedef struct TextEditor
{
    Line *firstLine;   // Pointer to the first visible line in the file
    Line *currentLine; // Pointer to the current line that the cursor is on
    Line *lastLine;    // Pointer to the last visible line in the file
    int cursorXPos;    // Current X position of the cursor
    int cursorYPos;    // Current Y position of the cursor
    int terminalRows;  // Horizontal size of the terminal
    int terminalCols;  // Vertical size of the terminal
}TextEditor;

void startTextEditor(const char filename[MAX_FILE_NAME_SIZE]);

#endif
