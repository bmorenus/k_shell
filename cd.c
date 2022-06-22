#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "shell.h"
#include "parse.h"
#include "linkedlist.h"
#include "cd.h"

#define MAXPATH 80

/*
 * Function: cd 
 * ------------
 * changes the current working directory based on the relative file path input.
 *
 * Example:
 * cd                    changes the cwd to $HOME
 * cd ../../             changes the cwd to two directories above the cwd
 * cd ./                 maintains the cwd
 * cd ../subdirectory    changes the cwd up one diretory and down into a subdir
 */
void cd(char* input) {

    if (input == NULL) {
        chdir(word_exp("~"));
    }

    char cwd[MAXPATH];
    getcwd(cwd, MAXPATH);
    
    LinkedListPtr cwd_ll_ptr = CreateLinkedList();
    ll_parse(cwd, cwd_ll_ptr, "/");
    
    LinkedListPtr input_ll_ptr = CreateLinkedList();
    ll_parse(input, input_ll_ptr, " /\n");
    
    if (cwd_ll_ptr == NULL || input_ll_ptr == NULL) {
        return;
    }

    modify_cwd_ll(input_ll_ptr, cwd_ll_ptr);
    
    char n_cwd[MAXPATH], g_cwd[MAXPATH];
    build_new_cwd(cwd_ll_ptr, n_cwd);
    chdir(n_cwd);

    getcwd(g_cwd, MAXPATH);

    DestroyLinkedList(input_ll_ptr);
    DestroyLinkedList(cwd_ll_ptr);
}

/*
 * Function: modify_cwd_ll
 * -----------------------
 * iterates over the input linked list to make the appropritate modifications
 * to the current working directory linked list.
 *
 * @param input_ll_ptr, input linked list ptr containing the cd arguments
 * @param cwd_ll_ptr, current working directory ptr containing the cwd path
 */
void modify_cwd_ll(LinkedListPtr input_ll_ptr, LinkedListPtr cwd_ll_ptr) {

    LinkedListNode* cur_node = input_ll_ptr->head;

    while (cur_node != NULL) {
        char* dir_cmd = cur_node->data;

        if (strcmp(dir_cmd, ".") == 0) {
            cur_node = cur_node->next;
            continue;
        } else if (strcmp(dir_cmd, "..") == 0) {
            RemoveRight(cwd_ll_ptr);
        } else {
            AddRight(cwd_ll_ptr, dir_cmd);    
        }
        cur_node = cur_node->next;
    }
}

/*
 * Function: build_new_cwd
 * -----------------------
 * generates a string containing the path to the updated cwd
 *
 * @param input_ll_ptr, input linked list ptr containing the cd arguments
 * @param cwd_ll_ptr, current working directory ptr containing the cwd path
 */
void build_new_cwd(LinkedListPtr cwd_ll_ptr, char* n_cwd) {

    LinkedListNode* cur_node = cwd_ll_ptr->head;

    strcpy(n_cwd, "/");
    while (cur_node != NULL) {
        strcat(n_cwd, cur_node->data);
        strcat(n_cwd, "/");
        cur_node = cur_node->next;
    }
}


