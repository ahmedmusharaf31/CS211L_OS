#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_SIZE 100

int main() {
    char filename[100];
    FILE *file;
    int fd, n;
    char buffer[MAX_SIZE];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Using system calls
    fd = open(filename, O_RDONLY);
    n = read(fd, buffer, MAX_SIZE);
    write(STDOUT_FILENO, buffer, n);
    close(fd);

    // Using fprintf and fscanf
    file = fopen(filename, "r");
    while (fscanf(file, "%s", buffer) != EOF) {
        fprintf(stdout, "%s ", buffer);
    }
    fclose(file);

    return 0;
}
