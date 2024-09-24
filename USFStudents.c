#include <stdio.h>
#include <string.h>

#define Name_Len 50
#define U_Len 10

struct student {
    char name[Name_Len + 1]; // This takes the name of the student
    int age; // Age of student
    char Unum[U_Len + 1]; // The Unumber
    float gpa; // their gpa
    int onCampus; // 1 for yes or 0 for no
    int has_paid; // 1 for yes or 0 for no
};

// This is to read a line of input
int read_line(char str[], int max_len) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && i < max_len - 1) { // THis keeps writing until they want a new line or they hit the max character limit
        str[i++] = ch;  // This stores the character in the string
    }
    str[i] = '\0'; // Null-terminate the string
    return i; // This returns characters read
}

int main() {
    // THis creates two student structure variables.
    struct student student1, student2;

    // This stuff is to get info about student 1.
    printf("Enter student name (first and last): ");
    read_line(student1.name, Name_Len + 1); // Have to use read_line because scanf don't read spaces

    printf("Enter your age: ");
    scanf("%d", &student1.age);
    getchar(); //this goes to next line

    printf("Enter your U number: ");
    read_line(student1.Unum, U_Len + 1); // Uses read_line for U number
    // No need to use getchar() since read_line handles input until newline

    printf("Enter your GPA: ");
    scanf("%f", &student1.gpa);
    getchar(); //this goes to next line

    printf("Do you live on campus? (1 for yes, 0 for no): ");
    scanf("%d", &student1.onCampus);
    getchar(); //this goes to next line

    printf("Have you paid for the current semester? (1 for yes, 0 for no): ");
    scanf("%d", &student1.has_paid);
    getchar(); //this goes to next line

    //this coppies data from student1 to student2
    student2 = student1;

    // THis changes student2's name, living status, and if they paid
    strcpy(student2.name, "New Name");// Changes the name to "New Name"
    student2.age = 12;  //Assigns age as 12
    strcpy(student2.Unum, "12345678");  // Assigns this as U number
    student2.gpa = 1.23; //THis their new GPA
    student2.onCampus = !student2.onCampus; //This switches their answer
    student2.has_paid = !student2.has_paid;  // Switches their answer

    // Print out the data for both students
    printf("\nStudent 1 Info:\n");
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("U Number: %s\n", student1.Unum);
    printf("GPA: %.2f\n", student1.gpa);
    printf("Lives on campus: %s\n", student1.onCampus ? "Yes" : "No");
    printf("Has paid: %s\n", student1.has_paid ? "Yes" : "No");

    printf("\nStudent 2 Info (Modified):\n");
    printf("Name: %s\n", student2.name);
    printf("Age: %d\n", student2.age);
    printf("U Number: %s\n", student2.Unum);
    printf("GPA: %.2f\n", student2.gpa);
    printf("Lives on campus: %s\n", student2.onCampus ? "Yes" : "No");
    printf("Has paid: %s\n", student2.has_paid ? "Yes" : "No");

    return 0;
}
