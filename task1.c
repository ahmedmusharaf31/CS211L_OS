#include <unistd.h>
#include <stdio.h>

int main() {
    char buffer[21]; // Maximum 20 characters + null terminator
    write(STDOUT_FILENO, "Enter up to 20 characters: ", 27);
    read(STDIN_FILENO, buffer, 20);
    buffer[20] = '\0'; // Ensure null termination
    write(STDOUT_FILENO, "You entered: ", 13);
    write(STDOUT_FILENO, buffer, 20);
    return 0;
}
