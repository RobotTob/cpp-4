#include <stdio.h>   // For input/output functions
#include <stdlib.h>  // For random number generation
#include <time.h>    // For seeding random number with current time

int main() {
    int guessAnswer;
    int guess;
    
    // Seed random number generator
    srand(time(NULL));
    guessAnswer = (rand() % 10) + 1;
    // Generate random number between 1 and 10
    

    // Display multiplication table
    printf("Multiplication Table:\n");
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= 12; j++) {
            printf("%4d", i * j); // This spaces it out a bit
        }
        printf("\n");
    }

    // Number guessing game
    printf("\nEnter your guess (1-10): ");
    scanf("%d", &guess);  // Corrected: pass the address of guess

    // Loop until the correct guess
    while (guess != guessAnswer) {
        if (guess > guessAnswer) {
            printf("Too high, try again: ");
        } else {
            printf("Too low, try again: ");
        }
        scanf("%d", &guess);  // Read the next guess
    }

    printf("You guessed it");

    return 0; // Returning 0 indicates successful execution
}
