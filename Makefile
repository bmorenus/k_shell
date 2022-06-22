all: compile run clean	

compile: shell.c cd.c tree.c ls.c game.c parse.c linkedlist.c
	gcc shell.c cd.c tree.c ls.c game.c parse.c linkedlist.c -o main

valgrind: compile
	valgrind -s --track-origins=yes  ./main

gdb: compile
	gdb -s ./main

run: compile
	./main

clean: 
	rm main
