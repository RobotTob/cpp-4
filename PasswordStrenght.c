//Max password length (25)
//Min password length (12 characters)
//Forbid repeats: may not contain sequences of three or more repeated characters 
//Allow pass phrases? (true / false). Min phrase length (20 characters) 
//Every password must contain letters, numbers, AND symbols
//Are optional tests required? (true / false). # min optional tests to pass (4).
//passphrases have 1 or more spaces. if they r allowed check if they also strong.
//to differeniate between regular assowrd and passphrase u cna see if there are spaces in it.
/*
 * COP 3515 – Fall Semester 2024
 *
 * Homework #1: Password Strength Meter
 *
 * (Tobin Mathew)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//this makes sure the string  at least one letter
bool hasLetter(const char *str) {
    while (*str) {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) { //this is for upper or lowercase letters
            return true;
        }
        str++;
    }
    return false;
}

// his checks if ti  a numerical value
bool hasNumber(const char *str) {
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            return true;
        }
        str++;
    }
    return false;
}

//THis makes sure it  atleast 2 numbers
bool hasTwoDigits(const char *str) {
    int count = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            count++;
        }
        if (count >= 2) {
            return true;
        }
        str++;
    }
    return false;
}

//THis checks if the sting  a special characer
bool hasSpecialChar(const char *str) {
    while (*str) {
        if (!((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))) {
            return true;  //It's a special character if this is true
        }
        str++;
    }
    return false;
}

//this sees if the string  atleast 2 special chars.
bool hasTwoSpecialChars(const char *str) {
    int count = 0;
    while (*str) {
        if (!((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))) {
            count++;
        }
        if (count >= 2) {
            return true;
        }
        str++;
    }
    return false;
}

//This checks if the character is repeated more than 2 times.
bool RepeatedSequences(const char *str) {
    while (*str && *(str + 1) && *(str + 2)) {
        if (*str == *(str + 1) && *str == *(str + 2)) {
            return true;
        }
        str++;
    }
    return false;
}


//this checks if it is a passphrase by checking for spaces
bool hasSpace(const char *str) {
    while (*str) {
        if (*str == ' ') {
            return true; //This checks for spaces in the password
        }
        str++;
    }
    return false;
}

//This function actually processes each password
void processFile(FILE *file, int fileNum) {
    int maxLen, minLen, allowPassphrase, optionalTests, minPhraseLen = 0, numOptionalTests = 0; //this sets up the values
    char buffer[256]; //the buffer stores each line in the file
    bool emptyLine = true;  //This skips the empty line

    //this reads the numbers at the top of the file to see what the reqs are for the passwords in the file
    fscanf(file, "%d %d %d %d", &maxLen, &minLen, &allowPassphrase, &optionalTests);//this reads the 4 integers integers in the file
    if (allowPassphrase) {//this runs if it allows psphrases
        fscanf(file, "%d", &minPhraseLen);  // If the statement is true it reads min phrase length
    }
    if (optionalTests) { //this is if it allows optional tests
        fscanf(file, "%d", &numOptionalTests);  //If this is true, it reads the number of tests that needs to pass
    }

    printf("Processing password file #%d\n\n", fileNum);//the 2nd \n is for a blank line after this line
    printf("Maximum password length: %d\n", maxLen);
    printf("Minimum password length: %d\n", minLen);
    printf("Pass phrases are %s allowed\n", allowPassphrase ? "" : "NOT");
    printf("Optional Tests are %s allowed\n\n", optionalTests ? "" : "NOT"); //the 2nd \n is for a blank line after this line

    //This is what actually goes through each password
    fgets(buffer, sizeof(buffer), file);  // this clears the old buffes after the rules

    while (fgets(buffer, sizeof(buffer), file) != NULL) { //this reads lines from the files
        int len = strlen(buffer);

        //this gets rid of any spaces in front of the line
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }


        //This skips the first empty line in each file
        if (emptyLine) {
            emptyLine = false;
            continue;
        }

        //This processes the passwords for different things
        bool passedRequired = true; //checks if the the rewuired rules are passed
        bool passedOptional = true;//checks if the the rewuired rules are passed
        bool passphraseFlag = false; //this chevcks if the line is a passphrase

        printf("Potential password: %s\n", buffer); //this displays the passwords. buffer holds the current line password

        //THis stuff is for required passwords.
        if (hasSpace(buffer)) {
            passphraseFlag = true;  //this lables pass phrases are pass phrases
            if (strlen(buffer) < 20) {  //pass phrases need to have at least 20 characters
                printf("The passphrase must be at least 20 characters long.\n");
                passedRequired = false;// this si if it doesn't have over 20 chars.
            }
        } else {
            //This is for regular passwords this checks if it meets the min length floor
            if (strlen(buffer) < minLen) {
                printf("The password must be at least %d characters long.\n", minLen);
                passedRequired = false; 
            }

            //This checks the max length if it's a regualr password
            if (strlen(buffer) > maxLen) {
                printf("The password must be fewer than %d characters.\n", maxLen);
                passedRequired = false;
            }
        }
        //it runs this if the password has more than 2 repeated chars.
        if (RepeatedSequences(buffer)) {
            printf("'The password must contain at least two special characters.\n");
            passedRequired = false;
        }

        //THis checks if it has at least one letter, one number, and one special character
        bool Letters = hasLetter(buffer);
        bool Numbers = hasNumber(buffer);
        bool Specials = hasSpecialChar(buffer);

        if (!(Letters && Numbers && Specials)) { //this is for passwords
            printf("The password must contain letters, numbers, AND symbols.\n");
            passedRequired = false;
        }

        //This is for optional tests
        if (optionalTests) {
            if (!hasLetter(buffer)) { //if it doesn't have atleast 1 letter
                printf("The password must contain at least one letter (lowercase or uppercase).\n");
                passedOptional = false;
            }
            if (!hasTwoDigits(buffer)) { //if it doesn't have atleast 2 numbers
                printf("The password must contain at least two digits.\n");
                passedOptional = false;
            }
            if (!hasTwoSpecialChars(buffer)) { //if it doesn't have atleast 2 symbols
                printf("The password must contain at least two special characters.\n");
                passedOptional = false;
            }
        }

        //This shows if it failed the first set of questions
        printf("Failed Required Tests: %s\n", passedRequired ? "None" : "[1-4]"); //it's [1-4] cause there r 4 questions
        
        //This prints if optional tests are allowed and this shows if it failed the 2nd set of questions
        if (optionalTests) {
            printf("Failed Optional Tests: %s\n", passedOptional ? "None" : "[4-7]");//it's [4-7] cause there r 4 questions starting from a new question 4
        }

        //This prints aboit pass phrase stuff if it is allowed
        if (allowPassphrase) {
            printf("Passphrase Detected: %s\n", passphraseFlag ? "true" : "false");
        }

        //This checks if it is able to be strong or not
        bool strongPassword = passedRequired && (!optionalTests || passedOptional); //it's only strong if both these are true.
        printf("The password is strong: %s\n", strongPassword ? "true" : "false"); //returns if it's true or false

        if (!strongPassword) {
            printf("Password failed - it cannot be used.\n");
        } else {
            printf("Password passed - it is strong and can be used.\n");
        }

        printf("\n");//this ends the line with an empty line for the next password
    }
}

int main() {
    FILE *file1, *file2, *file3;

    //This checks if the first file opened correctly
    if ((file1 = fopen("password1.txt", "r")) == NULL) { //mine is named password1
        printf("Error opening file1\n");
        return -1;
    }

    //This checks if the 2nd file opened
    if ((file2 = fopen("password2.txt", "r")) == NULL) { //mine is named password2
        fclose(file1);
        printf("Error opening file2\n");
        return -1;
    }

    //This checks if the third file opened
    if ((file3 = fopen("password3.txt", "r")) == NULL) {// mine is named password1
        fclose(file1);
        fclose(file2);
        printf("Error opening file3\n");
        return -1;
    }

    //this opens and processes each password file
    processFile(file1, 1);
    processFile(file2, 2);
    processFile(file3, 3);

    //This closes
    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;
}
