#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size = 1000000; // Large size to trigger memory overflow
    int i;

    // Allocate memory for the array
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Fill the array with values
    for (i = 0; i < size; i++) {
        arr[i] = i;
    }

    // Accessing within allocated memory
    printf("Accessing within allocated memory: %d\n", arr[size - 1]); // Accessing the last element of the array

    // Free the allocated memory
    free(arr);

    return 0;
}
