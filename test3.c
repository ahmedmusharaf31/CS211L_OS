#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int mypid = getpid();
    int childpid = fork();

    if (childpid < 0) {
        fprintf(stderr, "fork failed \n");
        exit(1);
    } else if (childpid == 0) {
        printf("Hello I am child %d, ID: %d \n", (int)getpid(), mypid);
    } else {
        printf("Hello I am parent %d, ID: %d \n", (int)getpid(), mypid);
    }
    return 0;
}
