#include <stdio.h>
#include "linkedlist.h"

#ifndef CD_H
#define CD_H

/*
 * Function: cd 
 * ------------
 * changes the current working directory based on the relative file path input.
 *
 * Example:
 * cd ../../             changes the cwd to two directories above the cwd
 * cd ./                 maintains the cwd
 * cd ../subdirectory    changes the cwd up one diretory and down into a subdir
 */
void cd(char* input);

/*
 * Function: modify_cwd_ll
 * -----------------------
 * iterates over the input linked list to make the appropritate modifications
 * to the current working directory linked list.
 *
 * @param input_ll_ptr, input linked list ptr containing the cd arguments
 * @param cwd_ll_ptr, current working directory ptr containing the cwd path
 */
void modify_cwd_ll(LinkedListPtr input_ll_ptr, LinkedListPtr cwd_ll_ptr);

/*
 * Function: build_new_cwd
 * -----------------------
 * generates a string containing the path to the updated cwd
 *
 * @param cwd_ll_ptr, pointer to the current working directory linked list
 * @param n_cwd, pointer to the updated current working directory string
 */
void build_new_cwd(LinkedListPtr cwd_ll_ptr, char* n_cwd);

#endif

