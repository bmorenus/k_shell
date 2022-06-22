#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

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
void parse(char* input, char* argv[], char* delimeter) {
    char* token;
    char* saveptr;

    // add newline as delimeter to ensure it is not included in token
    token = strtok_r(input, delimeter, &saveptr);
    int i = 0;
    while (token != NULL) {
        argv[i] = token;
        token = strtok_r(NULL, delimeter, &saveptr);
        i++;
    }
    argv[i] = NULL;
}

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
LinkedListPtr ll_parse(char* input, LinkedListPtr ll_ptr, char* delimeter) {
    char* token;
    char* saveptr;

    if (ll_ptr == NULL) {
        return NULL;
    }
    
    token = strtok_r(input, delimeter, &saveptr);

    while (token != NULL) {
        AddRight(ll_ptr, token);
        //printf("tok: %s\n", token);
        token = strtok_r(NULL, delimeter, &saveptr);
    }
    return ll_ptr;
}

