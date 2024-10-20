#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256
#define NUM_YEARS 43

//This finds the length of the titles
int get_title_length(const char* title) {
    return strlen(title);
}

int main() {
    FILE *file = fopen("AHPA #12 - Movie Data.txt", "r");
    if (!file) { //this is if is null
        printf("Error opening file.\n");
        return 1;
    }

    int year;
    double total_gross, average;
    int releases;
    char title[MAX_LEN];

    //THis stores the average lenght of the tieles
    double income_by_title_length[MAX_LEN] = {0};
    int title_length_count[MAX_LEN] = {0};

    //These are the movies we look for
    const char* star_wars_titles[] = {
        "Star Wars: Episode III - Revenge of the Sith",
        "Star Wars: Episode I - The Phantom Menace",
        "Star Wars: Episode VI - Return of the Jedi",
        "Star Wars: Episode V - The Empire Strikes Back",
        "Star Wars: Episode IV - A New Hope"
    };
    
    //stores the Star Wars titles
    const char* star_wars_pointers[5];

    for (int i = 0; i < 5; i++) {
        star_wars_pointers[i] = star_wars_titles[i];
    }

    // This skips the header
    char header[MAX_LEN];
    fgets(header, MAX_LEN, file);

    // This reads each line from the file
    while (fscanf(file, "%d %lf %d %lf %[^\n]s", &year, &total_gross, &releases, &average, title) != EOF) {
        int title_length = get_title_length(title);
        
        //This dds the average income to the corresponding title length
        income_by_title_length[title_length] += average;
        title_length_count[title_length] += 1;
    }

    fclose(file);

    //This finds the title length that made the most money
    int max_length = 0;
    double max_income = 0;
    for (int i = 0; i < MAX_LEN; i++) {
        if (income_by_title_length[i] > max_income) {
            max_income = income_by_title_length[i];
            max_length = i;
        }
    }

    //This gives the output the income for each title length
    printf("Average income by movie title length:\n");
    for (int i = 0; i < MAX_LEN; i++) {
        if (title_length_count[i] > 0) {
            printf("Title length %d: $%.2f\n", i, income_by_title_length[i]);
        }
    }

    printf("\nThe movie title length that made the most money was %d with $%.2f\n\n", max_length, max_income);

    //This outputs the Star Wars movies
    printf("Star Wars Movies in List:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i, star_wars_pointers[i]);
    }

    return 0;
}
