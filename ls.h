#include <stdio.h>

#ifndef LS_H
#define LS_H

/*
 * Function: ls
 * ------------
 * prints the file contents of the given directory
 *
 * @param path, the directory path to print
 */
void ls(char*);

/*
 * Function: print_file_details
 * ----------------------------
 * prints the relevant file details of the given file
 *
 * @param file_path, the file path to print the details of
 * @param filename, the name of the file
 */
void print_file_details(char*, char*);

/*
 * Function: format_permissions
 * ----------------------------
 * formats the file permissions information into a string based on the
 * provided file_bits
 *
 * @param file_bits, the st_mode file bits detailing the file information
 * returns a string of the relevant file permission information
 */
char* format_permissions(mode_t);

/*
 * Function: assign_permissions
 * ----------------------------
 * helper function for format_permissions that returns the appropriate
 * permission designation based on a bitwise comparison between the file_bits
 * and the given permission bit. 
 *
 * @param file_bits, the st_mode file bits detailing the file information
 * @param p_type, the type of file permission (read, write, execute)
 * @param p_bits, the system permission bits to compare
 * returns a char specifying the level of r, w, e permission based on p_bits
 */
char assign_permission(mode_t, char, int);

#endif


