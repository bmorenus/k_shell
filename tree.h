#include <stdio.h>

#ifndef TREE_H
#define TREE_H

/*
 * Function: tree
 * --------------
 * prints the sub-folders and files of a given directory path
 *
 * @param path, the directory path to print
 */
void tree(char* path);

/*
 * Function: tree_r
 * ----------------
 * prints the sub-folders and files of a given diretory path by recursively
 * calling the sub-directories and printing their respective files 
 *
 * @param path, the directory path to print
 * @param offset, the printing offset for a given directory entry
 */
void tree_r(char* path, int offset);

/*
 * Function: print_entry
 * ---------------------
 * prints the given filename entry with the provided offset
 *
 * @param filename, the filename to print
 * @param offset, the printing offset for a given file entry
 */
void print_entry(char* filename, int offset);

#endif


