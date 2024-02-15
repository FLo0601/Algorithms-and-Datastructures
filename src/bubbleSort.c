#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int[], int);

int main(void)
{
    int arr[] = { 2, 38, 236, 72, 234, 712, 71, 43, 52, 3, 5, 64, 85};
    int length = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < length; i++) printf("%d, ", arr[i]);
    printf("\n");
    bubbleSort(arr, length);
    for(int i = 0; i < length; i++) printf("%d, ", arr[i]);
    return EXIT_SUCCESS;
}

void bubbleSort(int arr[], int length) {
    for(int i = 0; i < length; ++i) {
        for(int ii = 0; ii < length - 1 - i; ++ii) {
            if(arr[ii] > arr[ii + 1]) {
                int temp = arr[ii];
                arr[ii] = arr[ii + 1];
                arr[ii + 1] = temp;
            }
        }
    }
}
