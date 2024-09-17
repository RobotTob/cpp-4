//Write a program in C to display the multiplication table for numbers 1-12 in a square table. just display it.
//Create a number guessing game that sets a number and then allows the user to guess it. 
//The number will be between 1 and 10
//Hint: 
// To calculate a random number between 1-10 for the game use:
// int guessAnswer =
// (rand() % 10) + 1; //
// random number
#include <stdio.h> //this for print statemets
#include <stdlib.h> //this is necessary for random number generation
#include <time.h> //This is to seed a random number every run

int main () {
    int guessAnswer; //the random number is an integer
    int guess; //this is the user's guess

    printf("Multiplication Table: \n");
    //The for loop below works as the following:
    /* The first loop has the first set of numbers
     when the first number starts in i it multilies that number from 1-12 in the 2nd for loop.
     after that i has gone through all 12 Js the i becomes a 2 and then that 2 gets multiplied from a new set of 12 Js form 1-12.
     Then it does that again and again until i reaches 12 and the 12th i reaches its 12th j. Giving 12x12 = 144.*/
    for (int i = 1; i <= 12; i++) { 
        for (int j = 1; j <= 12; j++) {
            printf("%4d", i * j); // This spaces it out a bit
        }
    printf("\n"); //this is for a new line after each increment of i is done.
    }

    srand(time(NULL)); //This randomizes the number every run. Without this the number is always 4.
    guessAnswer = (rand() % 10) + 1; //random number generator for #s between 1-10

    printf("\nEnter your guess (1-10):\n");
    scanf("%d", &guess);
    //this while loop runs as long as the guess isn't the same as the random number
    while (guess != guessAnswer){
        if (guess > guessAnswer){
            printf("Too high\n");
        } else{
            printf("Too low!\n");
        }
        scanf("%d", &guess); //the "&" is so scanf knows where to store the value at.
    }
    printf("You guessed it");//It prints this if the guess is correct
    return 0; //after the correct guess has been guessed the program ends
}