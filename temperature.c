/*
 * COP 3515 – Fall Semester 2024
 *
 * Homework #2: Spotting The Hacker
 *
 * (Tobin Mathew)
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

//This checks the number of 1s in the byte
int count_ones(unsigned char byte) {
    int count = 0;
    while (byte) {
        count += byte & 1;
        byte >>= 1;
    }
    return count;
}

//this prints the byte in binary
void print_binary(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
}

//This does the polatity check
void parity_check(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s.\n", filename);
        return;
    }

    unsigned char data[8], parity_byte;
    printf("** Part 1 - Parity Check Processing **\n");

    //This checks the trasmission line
    int line = 1;
    while (fscanf(file, "%hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu", 
                  &data[0], &data[1], &data[2], &data[3], 
                  &data[4], &data[5], &data[6], &data[7], 
                  &parity_byte) != EOF) {
        printf("Transmission line number: %d\nData stream: \n", line++);
        
        for (int i = 0; i < 8; i++) {
            printf("data item = %d , binary = ", data[i]);
            print_binary(data[i]);
            if (count_ones(data[i]) % 2 != count_ones(parity_byte) % 2) {
                printf("\nError in transmission byte %d\n", i + 1);
            } else {
                printf("\nNo error in transmission byte %d\n", i + 1);
            }
        }
        printf("Parity byte: %d\n", parity_byte);
    }

    fclose(file);
}

//This does the Checksum Check
void checksum_check(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s.\n", filename);
        return;
    }

    unsigned char data[8], checksum;
    printf("\n** Part 2 - Checksum Processing **\n");

    //Checks the transmission block
    while (fscanf(file, "%hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu", 
                  &data[0], &data[1], &data[2], &data[3], 
                  &data[4], &data[5], &data[6], &data[7], 
                  &checksum) != EOF) {
        printf("Data stream: \n");

        unsigned int sum = 0;
        for (int i = 0; i < 8; i++) {
            sum += data[i];
            printf("parityData[%d] = %d, binary = ", i, data[i]);
            print_binary(data[i]);
            printf("\n");
        }
        printf("Checksum: %d\n", checksum);

        printf("Sum of data items = %d , binary = ", sum);
        print_binary(sum);
        printf("\nChecksum value = %d , binary = ", checksum);
        print_binary(checksum);
        printf("\n");

        //this adds checksum to the sum and complement the result
        sum += checksum;
        printf("Sum after adding checksum = %d, binary = ", sum);
        print_binary(sum);
        sum = ~sum;
        printf("\nSum after complement = %d, binary = ", sum);
        print_binary(sum);
        printf("\n");

        if (sum == 0) {
            printf("Checksum: No errors in transmission\n");
        } else {
            printf("Checksum: Error detected in transmission\n");
        }
    }

    fclose(file);
}

//This does the Two-Dimensional Parity Check
void two_dimensional_parity_check(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s.\n", filename);
        return;
    }

    unsigned char data[8][8], horizontal_parity[8], vertical_parity[8];
    printf("\n** Part 3 - Two-Dimensional Parity Check **\n");

    //This reads the 8x8 block of data
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            fscanf(file, "%hhu", &data[row][col]);
        }
        fscanf(file, "%hhu", &horizontal_parity[row]);
    }
    for (int col = 0; col < 8; col++) {
        fscanf(file, "%hhu", &vertical_parity[col]);
    }

    printf("==> Processing Transmission Block 1\n");
    printf("Data streams:\n");
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            printf("%3d ", data[row][col]);
        }
        printf("[V: %d] [H: %d]\n", vertical_parity[row], horizontal_parity[row]);
    }

    // This checks teh row-wise (horizontal parity)
    printf("** Vertical processing transmission line 0 **\n");
    for (int row = 0; row < 8; row++) {
        int row_ones = 0;
        for (int col = 0; col < 8; col++) {
            row_ones += count_ones(data[row][col]);
            printf("val%d = %d, ", col + 1, data[row][col]);
            print_binary(data[row][col]);
            printf("\n");
        }
        printf("checkParityByte = %d, vertParityByte[%d] = %d\n", 0, row, vertical_parity[row]);
        if ((row_ones % 2 == 0 && count_ones(vertical_parity[row]) != 0)) {
            printf("Transmission line %d failed vertical parity\n", row);
        } else {
            printf("Transmission line %d passed vertical parity\n", row);
        }
    }

    //This checks the vertical parity
    printf("** Horizontal Processing transmission line 0 **\n");
    for (int col = 0; col < 8; col++) {
        int col_ones = 0;
        int checksum = 0;
        for (int row = 0; row < 8; row++) {
            col_ones += count_ones(data[row][col]);
            if (col == 4 || col == 6) {
                checksum += (1 << col);  // Add bit positions to checksum for demo purposes
                printf("Adding bit position %d to checksum: %d\n", col, 1 << col);
            }
        }
        printf("checkParityByte = %d, horizParityByte[%d] = %d\n", checksum, col, horizontal_parity[col]);
        if ((col_ones % 2 == 0 && count_ones(horizontal_parity[col]) != 0)) {
            printf("Transmission line %d failed horizontal parity\n", col);
        } else {
            printf("Transmission line %d passed horizontal parity\n", col);
        }
    }

    fclose(file);
}

int main() {
    //This processes the Parity Check Data
    parity_check("White House Transmission Data - Parity.txt");

    //This processes the Checksum Data
    checksum_check("White House Transmission Data - Checksum.txt");

    //This process the Two-Dimensional Parity Check Data
    two_dimensional_parity_check("White House Transmission Data - 2D Parity.txt");

    return 0;
}
