//Create a program that will ask a user what type of temperature they will be entering (F/C),
//then calculate a temperature that the facility can be set to in both temperature scales.
//Your program will convert the entered temperature - either from Fahrenheit to Celsius or from Celsius to Fahrenheit
//formula for f to c: (32°F − 32) × 5/9 = 0°C
//formula for c to f: (0°C × 9/5) + 32 = 32°F

//#define cels ((temp - 32) * 5.0 / 9.0)
//#define far ((temp * 9.0 / 5.0) + 32)
#include <stdio.h>

float celsToFahr(int temp) {
    return (temp * 9.0 / 5.0) + 32; // Celsius to Fahrenheit
}

float fahrToCels(int temp) {
    return (temp - 32) * 5.0 / 9.0; // Fahrenheit to Celsius
}

int main() {
    char therm; // temp being entered. c/f
    int temp;
    float cels;
    float fahr;

    printf("What type of temperature will you be entering (c/f)\n");
    scanf(" %c", &therm); // the space before %c is to get rid of any whitespace
    //this is if they write something other than c or f.
    if (therm != 'f' && therm != 'F' && therm != 'c' && therm != 'C') {
        printf("Invalid input. Please write either c or f");
        return 1;
    }

    printf("What temperaturecalue should be converted?\n");
    scanf(" %d", &temp);

    //cels = temp + 32

    if (therm == 'f' || therm == 'F') {
        cels = fahrToCels(temp);
        printf("Given a Fahrenheit temperature of %.2f,\n the equivalent Celsius temperature is %.2f\n", (float)temp, cels);//the end float allows for the 2 zeros after the decimal cause they r origionally floats
    }
    else if (therm == 'c' || therm == 'C') {
        fahr = celsToFahr(temp);
        printf("Given a Celsius temperature of %.2f,\n the equivalent Fahrenheit temperature is %.2f\n", (float)temp, fahr);//the end float allows for the 2 zeros after the decimal cause they r origionally floats
    }

    return 0;
}