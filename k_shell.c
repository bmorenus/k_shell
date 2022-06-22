#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>
#include <wordexp.h>
#include "parse.h"
#include "linkedlist.h"
#include "cd.h"
#include "tree.h"
#include "ls.h"
#include "k_shell.h"
#include "game.h"

#define MAXARGS 5
#define MAXNAME 80
#define MAXPATH 80
#define MAXLINE 60
#define NUMCOMMANDS 6 // must match number of commands in commands array

char* commands[] = {"cd", "tree", "ls", "shell", "end", "game"};

void (*command_functions[]) (char*) = {cd, tree, ls, shell, end, game};

/*
 * Function: exit
 * --------------
 * exits the calling process
 */
void end(char* argv) {
    exit(0);
}

/*
 * Function: shell
 * ---------------
 * creates a shell process
 *
 * @param argv, the arguments for the shell process
 */
void shell(char* argv) {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        print_shell_screen();
        char cmdline[MAXLINE], curr_dir[MAXPATH], hostname[MAXNAME];
        gethostname(hostname, MAXNAME);
        while (1) {
            curr_dir[0] = '\0'; // prevent previous cwd paths from appearing
            get_curr_dir(curr_dir);

            printf("%s: %s> ", hostname, curr_dir);
            Fgets(cmdline, MAXLINE, stdin);

            if (feof(stdin)) {
                exit(0);
            }
            eval(cmdline);
        }
    } else {
        wait(NULL);
    }
}

/*
 * Function: Fork 
 * --------------
 * fork() wrapper that identifies errors with child process, else returns pid
 *
 * @returns the pids of the calling parent and resulting child processes
 */
pid_t Fork(void) {
  pid_t pid;  
  if ((pid = fork()) < 0) {
    fprintf(stderr, "%s: %s\n", "fork error", strerror(errno));
    exit(0);
  }
  return pid;
}

/*
 * Function: Fgets
 * ---------------
 * fgets() wrapper that identifies and returns errors from stderr
 *
 * @param ptr, the ptr to the array to which the stream is copied
 * @param n, the max number of characters copied from stream to ptr
 * @param stream, the stdin stream containing user commands
 */
void Fgets(char* ptr, int n, FILE* stream) {
  if ((fgets(ptr, n, stream) == NULL) && ferror(stream)) {
    fprintf(stderr, "%s\n", "fgets error");
    exit(0);
  }
}

/*
 * Function: is_builtin_command
 * ----------------------------
 * returns index if the provided command is a built-in command, else -1
 *
 * @param cmd, the command entered by the user into the terminal
 * @returns built-in command index if built-in, else -1
 */
int get_builtin_command(char* cmd) {
    int i;
    for (i = 0; i < NUMCOMMANDS; i++) {
        if ((strcmp(commands[i], cmd)) == 0) {
            return i;
        }
    }
    return -1;
}

/*
 * Function: eval
 * --------------
 * evaluates the user input and calls the given command with provided args
 *
 * @param cmdline, string of user input from stdin
 */
void eval(char* cmdline) {
    char* argv[MAXARGS];
    parse(cmdline, argv, " \n");

    if (argv[0] == NULL)
        return;


    int cmd_index = get_builtin_command(argv[0]);
    if (cmd_index < 0) {
        handle_bin_command(argv[0], argv);
    } else {
        handle_builtin_command(cmd_index, argv);
    }
    return;
}

/*
 * Function: handle_bin_command
 * ----------------------------
 * accepts a command found in /bin and its arguments and executes in a
 * subprocess
 *
 * @param command, the binary command to execute
 * @param argv, the arguments for the command 
 */
void handle_bin_command(char* command, char* argv[]) {
    char bin_path[MAXPATH]; 
    strncpy(bin_path, "/bin/", MAXPATH);
    strcat(bin_path, argv[0]);
    argv[0] = bin_path;

    pid_t pid;
    pid = fork();

    if (pid == 0) {
        int res = execve(argv[0], argv, NULL);
        if (res < 0) {
            printf("k-shell: %s: command not found\n", command);
        }
    } else {
        wait(NULL);
    }
}

/*
 * Function: handle_builtin_command
 * --------------------------------
 * accepts a command found in the built-in functions array and its arguments 
 * and executes it
 *
 * @param command, the built-in command to execute
 * @param argv, the arguments for the command 
 */
void handle_builtin_command(int cmd_index, char* argv[]) {
    if (argv[1] != NULL) {
        argv[1] = word_exp(argv[1]);
    }
    void (*func) (char*) = command_functions[cmd_index];
    (*func) (argv[1]);
}

/*
 * Function: get_curr_dir
 * ----------------------
 * assigns the current directory to the given pointer
 *
 * @param curr_dir, the pointer to assign the current directory to
 */
void get_curr_dir(char* curr_dir) {
    char cwd[MAXPATH];
    char* token; 
    char* saveptr;
    
    getcwd(cwd, MAXPATH);

    if (strcmp(cwd, "/") == 0) {
        strcpy(curr_dir, cwd);
        return;
    }

    token = strtok_r(cwd, " /\n", &saveptr);
    while (token != NULL) {
        strcpy(curr_dir, token);
        token = strtok_r(NULL, " /\n", &saveptr);
    }
}

/*
 * Function: word_exp
 * ------------------
 * performs a word expansion on the provided function arguments
 *
 * @param argv
 */
char* word_exp(char* arg) {
    wordexp_t p;
    char** w = malloc(sizeof(char*) * MAXLINE);;

    wordexp(arg, &p, 0);
    w = p.we_wordv;
    return *w;
};

/*
 * Function: print_shell_screen
 * ----------------------------
 * prints the shell startup screen
 */
void print_shell_screen() {
    printf("\033[0;31m"
           "o__                    .__           .__  .__\n"   
           "|  | __           _____|  |__   ____ |  | |  |\n"  
           "|  |/ /  ______  /  ___/  |  \\_/ __ \\|  | |  |\n"  
           "|    <  /_____/  \\___\\|   Y   \\  ___/|  |_|  |__\n"
           "|__|_ \\         /____  >__|  / \\___  >____/ ____/\n"
           "     \\/              \\/    \\/      \\/           \n"
           "\033[0;37m");
}

/*
 * Function: main
 * --------------
 * faciliates the REPL and exits when eof or end command is entered
 */
int main(int argc, char* argv[]) {
    shell(*argv);
}
