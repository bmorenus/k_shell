#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>

#include "ls.h"

#define MAX_FILENAME 80
#define NUM_PERMISSIONS 10

// References concerning dirent.h retrieved from:
// https://pubs.opengroup.org/onlinepubs/7908799/xsh/readdir.html
//
// References concerning time.h retrieved from:
// https://pubs.opengroup.org/onlinepubs/7908799/xsh/time.h.html
//
// References concerning sys/stat.h retrieved from:
// https://pubs.opengroup.org/onlinepubs/009696799/basedefs/sys/stat.h.html

/*
 * Function: ls
 * ------------
 * prints the file contents of the given directory
 *
 * @param path, the directory path to print
 */
void ls(char* path) {

    if (path == NULL) {
        path = "."; 
    }

    DIR* dirp;
    dirp = opendir(path);
    
    int path_len = strlen(path);
    char* dir_path = malloc(sizeof(char) * (path_len + MAX_FILENAME));               
    
    if (dirp == NULL || dir_path == NULL) {
        return;
    }

    // add forward-slash to directory path if not present
    strcpy(dir_path, path);
    if (dir_path[path_len - 1] != '/') {
        dir_path[path_len] = '/';
        path_len++;
    }

    struct dirent* de;
    
    errno = 0;

    printf("%-15s%-10s%-10s%-12s%-28s%-16s\n",
            "Permissions", "Owner ID", "Group ID", "File Size", 
            "Last Accessed", "File Name"); 

    while ((de = readdir(dirp)) != NULL) {
        strcpy(&dir_path[path_len], de->d_name);     

        print_file_details(dir_path, de->d_name);

    }
    closedir(dirp);
    free(dir_path);
}

/*
 * Function: print_file_details
 * ----------------------------
 * prints the relevant file details of the given file
 *
 * @param file_path, the file path to print the details of
 * @param filename, the name of the file
 */
void print_file_details(char* file_path, char* filename) {
    struct stat    statbuf;

    if (stat(file_path, &statbuf) < 0) {
        printf("error\n");
    } else {
        char* permissions = format_permissions(statbuf.st_mode);
        char* l_time = ctime(&statbuf.st_atime);
        
        l_time[strlen(l_time) - 1] = '\0'; // remove newline from end of l_time

        printf("%-15s%-10u%-10u%-12lld%-28s%-16s\n",
                permissions, statbuf.st_uid, statbuf.st_gid, 
                statbuf.st_size, l_time, filename); 

        free(permissions);
    }
}

/*
 * Function: format_permissions
 * ----------------------------
 * formats the file permissions information into a string based on the
 * provided file_bits
 *
 * @param file_bits, the st_mode file bits detailing the file information
 * returns a string of the relevant file permission information
 */
char* format_permissions(mode_t file_bits) {
    char* permissions = malloc(sizeof(char) * NUM_PERMISSIONS);
    if (S_ISDIR(file_bits)) {
        permissions[0] = 'd';
    } else {
        permissions[0] = '-';
    }

    permissions[1] = assign_permission(file_bits, 'r', S_IRUSR);
    permissions[2] = assign_permission(file_bits, 'w', S_IWUSR);
    permissions[3] = assign_permission(file_bits, 'x', S_IXUSR);

    permissions[4] = assign_permission(file_bits, 'r', S_IRGRP);
    permissions[5] = assign_permission(file_bits, 'w', S_IWGRP);
    permissions[6] = assign_permission(file_bits, 'x', S_IXGRP);
    
    permissions[7] = assign_permission(file_bits, 'r', S_IROTH);
    permissions[8] = assign_permission(file_bits, 'w', S_IWOTH);
    permissions[9] = assign_permission(file_bits, 'x', S_IXOTH);

    return permissions;
}   

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
char assign_permission(mode_t file_bits, char p_type, int p_bits) {
    if ((file_bits & p_bits) == 0) {
        return '-';
    } else {
        return p_type;
    }
}

