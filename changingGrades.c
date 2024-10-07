#include <stdio.h>

//This function changes the D scores into C scores
void switcher(int *p) {
    //These contain the D values and the new C values for each of those D values
    int bad[] = {65, 67, 64, 61}; //The origional Ds
    int new[] = {75, 77, 74, 71}; //The C scorers for those D scores
    
    //This loops through all 15 numbers in the array
    for (int i = 1; i <= 15; i++) {
        // Check if the current value matches any of the D scores
        for (int j = 0; j < 4; j++) { //the 4 is because there are 4 values that are Ds
            if (*(p + i) == bad[j]) { //This points to teh origional Ds and
                *(p + i) = new[j]; // This assigns the old Ds into the new C score values
            }
        }
    }
}

int main() {
    //These are the original final exam scores, it is [16] because there are 15 numbers
    int finalExams[16] = {0, 90, 82, 65, 79, 67, 82, 94, 64, 88, 78, 92, 61, 96, 83, 74};
    //This prints out all 15 of the origional numbers
    printf("Scores before changing:\n");
    for (int i = 1; i <= 15; i++) {
        printf("%d ", finalExams[i]); //it prints out each number individually in the same line with 1 space in btwn.
    }
    printf("\n\n"); //the new line has to be in a seperate print statement from the loop because or else it prints a new line for each number 
    
    //This calls the switcher function to change the D scores
    switcher(finalExams);
    //This prints out the new D to C scores
    printf("Scores after changing:\n");
    for (int i = 1; i <= 15; i++) {
        printf("%d ", finalExams[i]); //it prints it out individually
    }
    printf("\n");
    
    return 0;
}
