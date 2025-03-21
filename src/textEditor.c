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
#include <sys/stat.h>

#include "textEditor.h"
#include "terminal.h"

#define IS_DIRECTORY 0
#define FILE_DOES_NOT_EXIST -1
#define FILE_EXISTS 1

FILE *file = NULL;
TextEditor *textEditor = NULL;

int doesFileExist(const char filename[MAX_FILE_NAME_SIZE]);


/**
 * @brief Start the text editor
 * 
 * @param filename 
 */
void startTextEditor(const char filename[MAX_FILE_NAME_SIZE])
{
    // Allocate memory for the text editor struct
    textEditor = (TextEditor *)calloc(1, sizeof(TextEditor));

    // REVIEW: should move this check to where we are parsing command line options?
    // Check if the user supplied a file name and check if that file exists
    switch(doesFileExist(filename))
    {
        case IS_DIRECTORY:
            // Path given is a directory, notify user and exit
            printf("ERROR: %s is a directory\n");
            exit(EXIT_FAILURE);
            break;

        case FILE_DOES_NOT_EXIST:
            // File given does not exist, so we will be opening an empty editor
            break;

        case FILE_EXISTS:
            // File exists, load the file and open the text editor
            break;

        default:

            break;
    }
}

/**
 * @brief Checks if the given file exists and check that is a file (not a dir, link, etc.)
 * 
 * @param filename 
 * @return int - 1 if file exists, 0 otherwise
 */
int doesFileExist(const char filename[MAX_FILE_NAME_SIZE])
{
    struct stat path_stat;

    // Check if the given path exists
    if(stat(filename, &path_stat) != 0)
    {
        return FILE_DOES_NOT_EXIST;
    }

    return S_ISREG(path_stat.st_mode); // Returns 1 if the given name is a file, 0 if not
}
