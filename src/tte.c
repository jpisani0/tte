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

    // Open an alternate screen for the program to open the file in and move the cursor to the top left of the screen
    openAlternateScreen();
    moveCursorAbsolute(SCREEN_TOP, SCREEN_LEFT);

    // TODO: load file here

    // Read the input to the terminal as it comes in
    while(scanForInput()) {}

    closeAlternateScreen();

    // Disable raw mode by setting the original terminal attributes
    disableRawMode(&originalTerminal);

    return 0;
}
