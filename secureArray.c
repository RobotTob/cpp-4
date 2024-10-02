//he maintains a sum of the array values at location [0] in the array.
//He won't give you access to this array
//but u boss say you need to get input from the user and then place it into the array.
//Each evening Peter will scan the code and remove any illegal references to his array.
/* using pointers, access Peter's array without him knowing it and place three
values that you got from the user (101, 63, 21) at locations 3, 6, and 9.
Recalculate the sum value and update it.*/
#include <stdio.h>

//This function will change the values of peter's array to the new one
void newArray(int *p) { //p points to the start of the array
    //Below are the values and positions that are going into the array
    int values[] = {101, 63, 21};
    int positions[] = {3, 6, 9};
    
    //This is to cycle through the 3 values and positions with the variable i
    for (int i = 0; i < 3; i++) {
        /*p holds the memory address of the first element in the array, so every time i gets
        added it adds 1 to the p index (so it goes to the next index). "*"is the location of the memory for the index
        so inside the parenthesis it finds the location of the memory for that index. The values[i] part updates the address
        with the value in the array named "values" above. */ 
        *(p + positions[i]) = values[i];
    }
    //THis is to calculate the sum and store it at the begining of the array at p[0]
    int sum = 0;
    for (int i = 1; i <= 9; i++) { //i starts at 1 because otherwise it will count the sum as one of the numbers to add
        sum += *(p + i); //This adds them all together when it goes through the iteration from 1 to 9'th location
    }
    *p = sum; //p is the first position of the array so this stores the sum at p[0]

}
int main() {
    //This is peter's current array
    int theArray[10] = {9,1,1,1,1,1,1,1,1,1};

    printf("Original array contents:\n");
    //this prints out each number in theArray by going over each iteration
    for (int i =0; i<10; i++) {
        printf("%d ", theArray[i]); //it's %d because it prints out the value in the array not the full array itself
    }
    printf("\n\n");//the new line has to be in a seperate print statement from the loop because or else it prints a new line for each number 

    newArray(theArray); //This goes back to the function newArray to change the values in theArray into the new array with the new values

    //this returns the same array as before but with the now updated variables.
    printf("Updated array contents:\n");
    //this prints out each number in theArray by going over each iteration
    for (int i =0; i<10; i++) {
        printf("%d ", theArray[i]); //it's %d because it prints out the value in the array not the full arry itself
    }
    printf("\n");//this is so the done statement is after the updated array numbers
    return 0;

}