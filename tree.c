#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

#include "tree.h"

#define STARTING_OFFSET 0
#define MAX_FILENAME 80
#define OFFSET_DIFF 5
#define OFFSET_STR 3

// References concerning dirent.h retrieved from:
// https://pubs.opengroup.org/onlinepubs/7908799/xsh/readdir.html
//
// References concerning sys/stat.h retrieved from:
// https://pubs.opengroup.org/onlinepubs/009696799/basedefs/sys/stat.h.html

/*
 * Function: tree
 * --------------
 * prints the sub-folders and files of a given directory path
 *
 * @param path, the directory path to print
 */
void tree(char* path) {

    if (path == NULL) {
        path = "."; 
    }
    printf("%s\n", path);
    tree_r(path, STARTING_OFFSET);
}
    
/*
 * Function: tree_r
 * ----------------
 * prints the sub-folders and files of a given diretory path by recursively
 * calling the sub-directories and printing their respective files 
 *
 * @param path, the directory path to print
 * @param offset, the printing offset for a given directory entry
 */
void tree_r(char* path, int offset) {

    DIR* dirp;
    dirp = opendir(path);

    int path_len = strlen(path);
    char* dir_path = malloc(sizeof(char) * (path_len + MAX_FILENAME));               
    
    if (dirp == NULL || dir_path == NULL) {
        return;
    }

    strcpy(dir_path, path);
    // add forward-slash to directory path if not present
    if (dir_path[path_len - 1] != '/') { 
        dir_path[path_len] = '/';
        path_len++;
    }

    struct stat    statbuf;
    struct dirent* de;

    errno = 0;

    while ((de = readdir(dirp)) != NULL) {
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }
        
        print_entry(de->d_name, offset);

        strcpy(&dir_path[path_len], de->d_name);     
                                           
        // get directory details with sys/stat library 
        if (stat(dir_path, &statbuf) < 0) {
            printf("error\n");
        } else {
            // if file is a directory, call tree_r w/ new directory path
            if (S_ISDIR(statbuf.st_mode)) {
                tree_r(dir_path, offset + OFFSET_DIFF);
            }
        }
    }
    closedir(dirp);
    free(dir_path);
}

/*
 * Function: print_entry
 * ---------------------
 * prints the given filename entry with the provided offset
 *
 * @param filename, the filename to print
 * @param offset, the printing offset for a given file entry
 */
void print_entry(char* filename, int offset) {
    int i, j;
    for (i = 0; i < (offset / OFFSET_DIFF); i++) {
        for (j = 0; j < OFFSET_DIFF; j++) {
            printf(" ");
        }
    }
    printf("|");

    for (i = 0; i < OFFSET_STR; i++) {
        printf("_");
    }
    printf(" %s\n", filename);
}
