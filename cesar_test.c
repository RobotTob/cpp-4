#include <stdio.h>
#include <stdlib.h>

FILE *clear, *secret;

int main() {
     // These are variables for the txt files

    // This opens the clearMessage txt file for reading
    if ((clear = fopen("clearMessage.txt", "r")) == NULL) { //the "r" reads from the file of clearMessage.txt
        printf("Error opening file\n"); //returns error of file didn't open
        return -1;
    }
    // This opens a file called secretMessage txt file to write in
    if ((secret = fopen("secretMessage.txt", "w")) == NULL) { //the "w" writes in the new file of secretMessage.txt
        printf("Error opening output file\n"); //returns error of file didn't open
        return -1;
    }

    // Read the file character by character and apply Caesar Cipher
    int ch;
    while ((ch = fgetc(clear)) != EOF) { //it returns error code EOF if the file's not closed right
        // This is for charachters that are uppercase letter
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + 3) % 26) + 'A';  // Shift within uppercase range
        }
        // This is for charachters that are lower letter
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + 3) % 26) + 'a';  // Shift within lowercase range
        }
        // This prints the new characters into the new secret file
        fprintf(secret, "%c", ch);
    }

    fclose(clear);  // Close the clearMessage.txt file
    fclose(secret); // Close the secretMessage.txt file
}
