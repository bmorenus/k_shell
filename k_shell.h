#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

#ifndef SHELL_H
#define SHELL_H

/*
 * Function: exit
 * --------------
 * exits the calling process
 */
void end(char* argv);

/*
 * Function: Shell
 * ---------------
 * creates a shell process
 */
void shell(char* argv);

/*
 * Function: Fork 
 * --------------
 * fork() wrapper that identifies errors with child process, else returns pid
 *
 * @returns the pids of the calling parent and resulting child processes
 */
pid_t Fork(void);

/*
 * Function: Fgets
 * ---------------
 * fgets() wrapper that identifies and returns errors from stderr
 *
 * @param ptr, the ptr to the array to which the stream is copied
 * @param n, the max number of characters copied from stream to ptr
 * @param stream, the stdin stream containing user commands
 */
void Fgets(char* ptr, int n, FILE* stream);

/*
 * Function: is_builtin_command
 * ----------------------------
 * returns 1 if the provided command is a built-in command, returns 0 if not
 *
 * @param cmd, the command entered by the user into the terminal
 * @returns 1 if built-in, else 0
 */
int get_builtin_command(char* cmd);

/*
 * Function: eval
 * --------------
 * evaluates the user input and calls the given command with provided args
 *
 * @param cmdline, string of user input from stdin
 */
void eval(char* cmdline);

/*
 * Function: handle_bin_command
 * ----------------------------
 * accepts a command found in /bin and its arguments and executes in a
 * subprocess
 *
 * @param command, the binary command to execute
 * @param argv, the arguments for the command 
 */
void handle_bin_command(char* command, char* argv[]);

/*
 * Function: handle_builtin_command
 * --------------------------------
 * accepts a command found in the built-in functions array and its arguments 
 * and executes it
 *
 * @param command, the built-in command to execute
 * @param argv, the arguments for the command 
 */
void handle_builtin_command(int cmd_index, char* argv[]);

/*
 * Function: get_curr_dir
 * ----------------------
 * assigns the current directory to the given pointer
 *
 * @param curr_dir, the pointer to assign the current directory to
 */
void get_curr_dir(char* curr_dir); 

/*
 * Function: word_exp
 * ------------------
 * performs a word expansion on the provided function arguments
 *
 * @param argv
 */
char* word_exp(char* arg);

/*
 * Function: print_shell_screen
 * ----------------------------
 * prints the shell's ASCII art title screen
 */
void print_shell_screen();

int main();

#endif

