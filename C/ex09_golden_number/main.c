/* Ask the user to guess a number between 0 and 99. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int tries=0, number, guess;
    time_t t;
    srand((unsigned) time(&t));     // initialize the random number generator
    number = rand() % 100;
    while (1) {
        tries++;
        printf("Please enter a number between 0 and 99. n = ");
        while (!scanf("%d", &guess)) {
            printf("This is not a number. Please try again. n = ");
            while ((guess = getchar()) != '\n' && guess != EOF) {}  // flush stdin
        }
        if (guess < number) {
            printf("The number is higher.\n");
        } else if (guess > number) {
            printf("The number is lower.\n");
        } else {
            printf("Well done. Total number of tries: %d.\n", tries);
            return 0;
        }
    }
}
