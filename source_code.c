//COPILOT:

#include <stdio.h>

int main() {
    int secret = 7;          // fixed secret number
    int guess;  // variable to store the user's guess
    int attempts = 3; // number of attempts allowed
    int status;

    printf("Guess a number between 1 and 10:\n");

    for (int i = 1; i <= attempts; i++) { 
        printf("Attempt %d/%d. Enter your guess: ", i, attempts);
        
        while (1) {
            status = scanf("%d", &guess);
            if (status == 1) {
                break;
            } else {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n'); // Clear the input buffer
                printf("Attempt %d/%d. Enter your guess: ", i, attempts);
            }
        }

        if (guess < 1 || guess > 10) {
            printf("Please enter a number between 1 and 10.\n");
            i--; // Do not count this as an attempt
            continue;
        }

        if (guess == secret) {
            printf("Correct! You win!\n");
            return 0;   // stop immediately
        } else if (guess < secret) {
            printf("Too low! ");
        } else {
            printf("Too high! ");
        } if (i != attempts) {
            printf("Try again.\n");
        }
    }

    printf("\nSorry, you lose. The number was %d.\n", secret);
    return 0;
}
