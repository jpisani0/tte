/**
 * @file tte.c
 * @author J. Pisani (jgp9201@gmail.com)
 * @brief Main driver for tte
 * @version 0.1
 * @date 2025-01-22
 */

#include "tte.h"

// REVIEW: should prob replace all instances of printf() and fflush() with write()

int main(int argc, char** argv)
{
    const char* functionName = "tte():";
    char c = 0;
    termios originalTerminal; // Original terminal attributes
    FILE *fp = NULL;

    // Get the user's inputted options
    parseOptionsAndFilename(argc, argv);

    // Put terminal into raw mode
    enableRawMode(&originalTerminal);

    // Open an alternate screen for the program to open the file in and move the cursor to the top left of the screen
    openAlternateScreen();
    moveCursorAbsolute(SCREEN_TOP, SCREEN_LEFT);

    // TODO: load file here

    // Read the input to the terminal as it comes in until the user asks to exit
    while(scanForInput()) {}

    // Close the alternate screen and return to the original
    closeAlternateScreen();

    // Disable raw mode by setting the original terminal attributes
    disableRawMode(&originalTerminal);

    // Free dynamically allocated memory
    free((void *)options);

    return 0;
}

/**
 * @brief Parses the command line options
 * 
 * @param argc - number of command line inputs
 * @param argv - the command line inputs
 * @return options 
 */
void parseOptionsAndFilename(int argc, char** argv)
{
    int opt = 0;

    // Allocate memory for options
    options = (Options *)calloc(1, sizeof(options));

    // Set default options
    options->readonly = false;
    strcpy(options->filename, "");

    // Return if no options were sent
    if(argc < 2)
    {
        return;
    }

    // Parse through the options
    while((opt = getopt(argc, argv, "r")) != -1)
    {
        switch(opt)
        {
            case 'r':
                options->readonly = true;
                break;

            default:
                // Unknown option
                printHelp();
                exit(EXIT_FAILURE);
        }
    }

    // Capture the last argument (if provided) which should be the file name
    if(optind < argc)
    {
        strcpy(options->filename, argv[optind]);
    }
}

/**
 * @brief Prints the help/usage guide
 * 
 */
void inline printHelp(void)
{
    printf( "Usage: tte [options] <filename>\n"
            "Options:\n"
            "\t-r\t\topen file in read-only mode\n"
            "\n\tfilename\tname of file to open\n");
}
