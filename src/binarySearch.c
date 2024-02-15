#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int[], int, int);
int CrystalBallSearch(short[], int);

int main(void)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int length = sizeof(arr) / sizeof(arr[0]);
    int index = binarySearch(arr, 5, length);
    printf("Index of 5: %d\n", index);

    short floors[] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
    length = sizeof(floors) / sizeof(floors[0]);
    index = CrystalBallSearch(floors, length);
    printf("Floor at which balls would break: %d\n", index);
    return EXIT_SUCCESS;
}

// finds needle/value in sorted array
// get middle point of the array
// checks if middlepoint value is greater or smaller then needle
// repeats with the half below or above middle point depending on result
int binarySearch(int arr[], int needle, int high) {
    int low = 0;

    do {
        int midpoint = low + (high - low) / 2;
        int value = arr[midpoint];

        if (value == needle) return midpoint;
        else if (value > midpoint) low = midpoint + 1;
        else high = midpoint;

    } while (low < high);
    return -1;
}

// find at which floor the crystal balls break
// jumps by squareroot because there are only two attempts to drop one ball
int CrystalBallSearch(short arr[], int high) {
    int jmpAmount = floor(sqrt((double)high));
    int i = jmpAmount;
    printf("Test1 %d\n", i);

    for(; i < high; i += jmpAmount) {
        if (arr[i] == 1) break;
        printf("Test2 %d\n", i);
    }

    i -= jmpAmount;

    for(int ii = 0; ii <= jmpAmount && i < high; ++ii, ++i) {
        if(arr[i] == 1) return i;
    }

    return -1;
}
