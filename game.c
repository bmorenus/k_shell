#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "shell.h"

#define GUESS_RANGE_LO 1
#define GUESS_RANGE_HI 9
#define MAX_INPUT 20
#define STARTING_GUESS_VAL -1

/*
 * Function: game 
 * --------------
 * a guessing game where the user must guess a number between 1-9. If they
 * guess right, they win and achieve immense satisfaction in life.
 */
void game() {
    srand(time(NULL));
    int ans = (rand() % GUESS_RANGE_HI) + GUESS_RANGE_LO;
    char *p, input[MAX_INPUT];
    int guess = STARTING_GUESS_VAL;

    printf("GUESS THE NUMBER!\n");
    while (guess != ans) {
        printf("Please enter a number between 1 and 9: ");

        while (fgets(input, sizeof(input), stdin)) {
            guess = strtol(input, &p, MAX_INPUT);
            if (p == input || *p != '\n') {
                printf("Please enter a number between 1 and 9: ");
            } else break;
        }
    }
    printf("YOU WIN!\n");

}
