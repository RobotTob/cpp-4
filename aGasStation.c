//station has 4 pumps
//Tanks have capacity of 100,75,50, and 150
//Every time a car fills up it takes 10 gallons.
// when car arrives carArrived function will return with a pump number.
//after each a car is done print out the current contents of all four Tanks.
//make program that tracks the gas amount for each pump. Update the amount of gas remaining in a Tank when a car fills up.
//When a Tank gets to less than 20 gallons of gas remaining, make a call to request a refill truck visit the station (refillRequest)
//This will cause the Tank to be refilled automatically.

#include <stdio.h>

// This has the predefined values for the tank capacities
#define Tank1 100
#define Tank2 75
#define Tank3 50
#define Tank4 150
#define spentFule 10 //default for all cars
#define gasLimit 20 //it refills when gas is less than 20 gallons

// Function declarations
int carArrived(void);
void refillRequest(int Tank);
void tankLevels(int Tanks[], int size);

int main() {
    //This stores teh tank info. THis array starts with 1
    int Tanks[4] = {Tank1, Tank2, Tank3, Tank4};

    while (1) { //the while 1 is for an infinite loop
        int pump = carArrived(); //This gets the pump number

        //this lets you chose the pumps starting from 1 instead of 0
        pump -= 1;

        if (pump >= 0 && pump < 4) {  //This is to make sure it is one of the 4 pumps
            if (Tanks[pump] >= spentFule) {
                Tanks[pump] -= spentFule;  //This lowers the quantity of fule every time it is spent
                printf("Car fuled at pump %d.\n", pump + 1); //This is so it can show the pump that the car pulled up to
            } else {
                printf("Pump %d needs more fuel.\n", pump + 1); //it prints this if it needs more fule
            }

            //This shows the current tank levels
            tankLevels(Tanks, 4);

            //This checks if the tank needs refilling
            if (Tanks[pump] < gasLimit) {
                refillRequest(pump + 1); //The +1 is so it starts at number1
                //THis is how it knows what tank to be full
                if (pump == 0)
                    Tanks[pump] = Tank1;
                else if (pump == 1)
                    Tanks[pump] = Tank2;
                else if (pump == 2)
                    Tanks[pump] = Tank3;
                else
                    Tanks[pump] = Tank4;
            }
        } else {
            printf("That is not a pump number.\n"); //if they enter an invalid pump
        }
    }
    return 0;
}

//This lets you chose which pump the car is at
int carArrived(void) {
    int pump;
    printf("Enter pump number (1-4): ");
    scanf("%d", &pump);
    return pump;
}

//This lets you chose which pump needs a refil
void refillRequest(int Tank) {
    printf("Tank %d needs a refil.\n\n", Tank);
}

//This shows the current levels of all the tanks
void tankLevels(int Tanks[], int size) {
    int i;
    printf("Current amount of gas in of all four tanks:\n");
    for (i = 0; i < size; i++) {
        printf("Tank %d: %d gallons\n", i + 1, Tanks[i]); //This shows the tank numbers starting from 1
    }
}
