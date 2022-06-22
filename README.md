# **README - k_shell**

The k_shell is a shell terminal that allows the user to enter various commands to interact with your computer's file system. 

![image](https://user-images.githubusercontent.com/58372262/174961385-bd0f3171-b511-47c6-9da0-400ee38c38df.png)

## Get Started:
1. Clone the k_shell repository into a local directory
2. Run the Makefile by entering the command `make`
3. Execute the commands below to interact with the file system

## Commands:
1. `cd [RELATIVE FILEPATH]` - changes current working directory

        The cd command allows the user to change their current working directory by inputing a relative file path after the command.  
                Calling the cd command without a relative filepath argument will bring the user to their respective $HOME directory.

2. `ls [RELATIVE FILEPATH]` - lists all files in current working directory

        ![image](https://user-images.githubusercontent.com/58372262/174960799-40e2e313-744d-4697-b805-bdf9bf13b319.png)

        The ls command lists all directories and files located in the current working directory. It also provides a number of  
        other details concerning the files to include permissions, owner/group IDs, file size, and last date/time of access.

3. `tree [RELATIVE FILEPATH]` - prints a visual depiction of the given directory

        ![image](https://user-images.githubusercontent.com/58372262/174962105-ea803a13-08bb-4f46-898f-1ab64426d2fa.png)

        The tree program uses a depth-first search algorithm to list all files and directories found in the current working  
        directory and provides a visual depiction of the file tree for review. When no arguments are provided with the  
        function it runs on the current working directory, otherwise if a relative path is provided as an argument it  
        runs on the relative file path.

4. `shell` - opens a new shell within the current shell

        The shell program runs a user interactive shell that prompts the user for command inputs and subsequently runs  
        those commands. The user may input commands that are built-in to the shell itself or commands that are found in  
        the /bin directory on the user's machine.

5. `game` - run a fun, user-interactive game

        The game command runs the game program that asks the user to guess a number between 1 and 10. If the user guesses  
        correctly, they win. Otherwise, they continue to guess until they get the correct number.

6. `end` - closes the current shell

        closes the current k_shell session
