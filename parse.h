#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

#ifndef PARSE_H
#define PARSE_H

/*
 * Function: parse 
 * ---------------
 * accepts an input string, tokenizes it, and assigns the tokens to an array.
 *
 * @param input, the input string
 * @param argv, array of char* to which the tokens are assigned
 * @param cmd_buff, pre-formatted array to which the input command is assigned
 * @param delimeter, delimeters separating the relevant input tokens
 */
char** parse(char* input, char* argv[], char* delimeter);

/*
 * Function: ll_parse 
 * ------------------
 * accepts an input string, tokenizes it, and assigns the tokens to a linked
 * list.
 *
 * @param input, the input string
 * @param list, linkedlist to which the tokens will be added
 * @param delimeter, delimeters separating the relevant input tokens
 * @returns the the linked list with all tokens
 */
LinkedListPtr ll_parse(char* input, LinkedListPtr ll_ptr, char* delimeter);

#endif
