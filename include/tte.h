/**
 * @file tte.h
 * @author J. Pisani (jgp9201@gmail.com)
 * @brief Contains functionality for the main program
 * @version 0.1
 * @date 2025-01-28
 */

#ifndef _TERMINAL_TEXT_EDITOR_H
#define _TERMINAL_TEXT_EDITOR_H

#include <string.h>
#include <getopt.h>
#include <stdlib.h>

#include "terminal.h"
#include "rawIO.h"
#include "textEditor.h"

// REVIEW: should we make a struct to hold options in or an int to use bits to set options
// TODO: add options to open file on particular line
typedef struct OPTIONS
{
    bool readonly; // Open the file in read-only mode
    char filename[MAX_FILE_NAME_SIZE]; // Name of the file
}Options;

#endif