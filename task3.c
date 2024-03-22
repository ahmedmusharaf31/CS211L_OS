#include <stdio.h>

int main() {
    FILE *file;
    int num, count = 0;
    double sum = 0, average;

    file = fopen("Average.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%d", &num) != EOF) {
        sum += num;
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("No numbers found in the file.\n");
        return 1;
    }

    average = sum / count;
    printf("Average of numbers in the file: %.2lf\n", average);

    return 0;
}
