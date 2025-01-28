/**
 * @file tte.c
 * @author J. Pisani (jgp9201@gmail.com)
 * @brief Functions supporting the tte program
 * @version 0.1
 * @date 2025-01-25
 */

#include <termios.h>
#include <stdio.h>

#define clearScreen() printf("\e[1;1H]\e[2J]") // Clears the terminal and places cursor in top right corner

/**
 * @brief 
 * 
 * @return int 
 */
int save_current_terminal()
{
    
}

/**
 * @brief Create a new terminal to host tte in separate from what was being used before
 * 
 * @return int 
 */
int create_new_terminal()
{

}
