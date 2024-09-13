//Open the file "clearMessage.txt"
//Read each character of text using fgetc
//Convert each ASCII character to its numeric equivalent.
//Apply the Caesar Cipher and increment each character by 3. so +3
//Only convert alphabetic characters – leave all other characters unchanged.
//Convert each character back to its ASCII value.
//Write the encoded message out to the file "secretMessage.txt". This is different from origional txt file.
//NO LOOPS ALLOWED
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000

int main() {
    char str[MAX_LEN];
    FILE* pFile;

    // Open the file
    // pFile = fopen("clearMessage.txt", "r");
    // if (pFile == NULL) {
    //     printf("Error opening file\n");
    //     return 1;
    // }
    FILE *file;

    if ((file = fopen("clearMessage.txt", "r")) == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    

    // Read the file character by character
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);  // Print each character to the console
    }

    fclose(file); // Close the file
    return 0;
}