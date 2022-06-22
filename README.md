## **Brian Morenus - a5 README
Generated on 04/03/2022 03:21:12 PM EDT, by brianmorenus

### List of built-in commands to test:
cd [RELATIVE FILEPATH] - changes current working directory
ls [RELATIVE FILEPATH] - lists all files in current working directory
tree [RELATIVE FILEPATH] - prints a visual depiction of the given directory
shell - opens a new shell within the current shell
end - closes the current shell
game - run a fun, user-interactive game

#### This directory contains the following files:
1. Makefile
2. README.md
3. a.out
4. cd.c
5. cd.h
6. game.c
7. game.h
8. linkedlist.c
9. linkedlist.h
10. ls.c
11. ls.h
12. main
13. parse.c
14. parse.h
15. shell.c
16. shell.h
17. test
18. tree.c
19. tree.h

## Makefile
### Description
Makefile for the K-shell program

### Dependencies

---------------------------

## README.md
### Description
README for the K-shell program

### Dependencies

---------------------------

## cd.c
### Description
cd built-in program file. The cd command allows the user to change their
current working directory by inputing a relative file path after the command.
Calling the cd command without a relative filepath argument will bring the
user to their respective $HOME directory.

### Dependencies
stdio.h
string.h
unistd.h
shell.h
parse.h
linkedlist.h
cd.h

---------------------------

## cd.h
### Description
cd built-in header file

### Dependencies
stdio.h
linkedlist.h

---------------------------

## game.c
### Description
game built-in program file. The game command runs the game program that asks
the user to guess a number between 1 and 10. If the user guesses correctly,
they win. Otherwise, they continue to guess until they get the correct number.

### Dependencies
stdio.h
time.h
ctype.h
shell.h

---------------------------

## game.h
### Description
game built-in header file

### Dependencies
stdio.h
ctype.h

---------------------------

## linkedlist.c
### Description
linked-list data file

### Dependencies
stdio.h
string.h
linkedlist.h

---------------------------

## linkedlist.h
### Description
linked-list header file

### Dependencies
stdio.h
stdlib.h
stdint.h

---------------------------

## ls.c
### Description
ls built-in program file. The ls command lists all directories and files
located in the current working directory. It also provides a number of other
details concerning the files to include permissions, owner/group IDs, file
size, and last date/time of access.

### Dependencies
stdio.h
stdlib.h
string.h
unistd.h
sys/types.h
dirent.h
errno.h
sys/stat.h
time.h
ls.h

---------------------------

## ls.h
### Description
ls built-in header file

### Dependencies
stdio.h

---------------------------

## parse.c
### Description
parse built-in program file. The parse program is a utility function that
parses the user input and ensures that the commands and arguments inputted
by the user are read into the shell program correctly.

### Dependencies
stdio.h
string.h
linkedlist.h

---------------------------

## parse.h
### Description
parse built-in header file

### Dependencies
stdio.h
string.h
linkedlist.h

---------------------------

## shell.c
### Description
shell built-in program file. The shell program runs a user interactive shell
that prompts the user for command inputs and subsequently runs those commands.
The user may input commands that are built-in to the shell itself or commands
that are found in the /bin directory on the user's machine.

### Dependencies
stdio.h
stdlib.h
string.h
unistd.h
sys/types.h
sys/wait.h
errno.h
signal.h
limits.h
wordexp.h
parse.h
linkedlist.h
cd.h
tree.h
ls.h
shell.h
game.h

---------------------------

## shell.h
### Description
shell built-in header file

### Dependencies
stdio.h
string.h
linkedlist.h

---------------------------

## tree.c
### Description
tree built-in program file. The tree program uses a depth-first search
algorithm to list all files and directories found in the current working
directory and provides a visual depiction of the file tree for review.
When no arguments are provided with the function it runs on the current
working directory, otherwise if a relative path is provided as an argument
it runs on the relative file path.

### Dependencies
stdio.h
stdlib.h
string.h
dirent.h
errno.h
sys/stat.h
tree.h

---------------------------

## tree.h
### Description
tree built-in header file

### Dependencies
stdio.h

---------------------------
