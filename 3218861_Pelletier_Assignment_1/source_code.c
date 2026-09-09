// File: FALL2026_EECSS348_Assignment_1
// Author: Mikayla Pelletier
// Creation date: 9/7/2026
// Revision date: 9/8/2026
// All collaborators: Sydney Moroney, Madelyn Armitage, and Savena Lin
// Other sources for the code: Gemini, Claude, and Copilot
// Description: C program that picks a secret number between 1 and 10. The user gets up to 3 tries to guess the number.
// Inputs: Number between 1 and 10 up to three times
// Outputs: Feedback on whether the guess is too high, too low, or correct
// Revisions: Added edgecase handling for invalid input and out of range numbers. Added comments to explain the code.

#include <stdio.h> // include the standard input/output library

int main() { // main function where the program starts execution
    int secret = 7; // fixed secret number
    int guess;  // variable to store the user's guess
    int max_attempts = 3; // number of attempts allowed
    int status; // temporary variable to store the return value of scanf

    printf("Guess a number between 1 and 10:\n"); // prompt user to guess a number

    // Loop for the number of attempts allowed. Authored by Copilot.
    for (int attempt = 1; attempt <= max_attempts; attempt++) { // loop through the number of attempts
        printf("Attempt %d/%d. Enter your guess: ", attempt, max_attempts); // prompt user for their guess

        // A while loop to make sure the user inputs a integer. Adapted from a Gemini code example.
        while (1) { //loops until valid input is received (1=True in c)
            status = scanf("%d", &guess); // stores user input in guess varible and status becomes true or false based off success.
            if (status == 1) { // if the input is valid (1=True in c). Will be true if the user inputs a number.
                break; // exit the loop if the input is valid
            } else { // if the input is invalid (0=False in c). Will be false if the user inputs a letter or symbol.
                printf("Invalid input. Please enter a number.\n"); // informs user they entered an invalid input
                while (getchar() != '\n'); // Clear the input buffer
                printf("Attempt %d/%d. Enter your guess: ", attempt, max_attempts); // prompt user for their guess again
            } // if the input is valid, continue with the game
        } // end of while loop for input validation

        // Check if the guess is within the valid range. Authored by me with help from Gemini and Copilot.
        if (guess < 1 || guess > 10) {  // Enter if statment if the guess is not in valid range.
            printf("Please enter a number between 1 and 10.\n"); // informs user they entered an invalid number.
            attempt--; // Deletes the attempt number added so it doesn't count as attempt.
            continue; // skips the rest of the loop and goes to the next iteration
        } // if the guess is valid, continue with the game

        // Evaluate the guess and provide feedback.
        // Based on copilot code example, edited by me.
        if (guess == secret) { // if the guess is equal to the secret number
            printf("Correct! You win!\n"); // informs user they guessed the secret number
            return 0;   // stop immediately
        } else if (guess < secret) { // if the guess is less than the secret number
            printf("Too low! "); // informs user their guess is too low
        } else { // if the guess is greater than the secret number
            printf("Too high! "); // informs user their guess is too high
        } if (attempt != max_attempts) { // if the user has not used all their attempts
            printf("Try again.\n"); // prompts user to try again
        } // end of if statment
    } // ends and exits loop if the user has used all their attempts without guessing the secret number

    printf("\nSorry, you lose. The number was %d.\n", secret); // informs user they have lost and what the secret number was
    return 0; // ends the program
} // end of main function
