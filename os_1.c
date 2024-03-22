#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

// int main(int argc, char* argv[])
// {
//     char *fcs="CE and CS";
//     printf("%s",fcs);

//     exit(0);
// }

// int main(int argc, char* argv[])
// {
//     int i;
// for(i=0; i < argc; i++)
// printf(" &argv[%d] = %p \n", i, &argv[i]);
// printf("--------------------------------\n");
// for(i=0; i < argc; i++)
// printf(" argv[%d] = %p \n", i, argv[i]);
// printf("--------------------------------\n");
// for(i=0; i < argc; i++)
// printf(" argv[%d] = %s \n", i, argv[i]);
// return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include<sys/wait.h>

// int main(int argc, char *argv[]) {
//     printf("hello world (pid:%d)\n", (int) getpid());
//     int rc = fork();
//     if (rc < 0) {
//         // fork failed
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) {
//         // child (new process)
//         printf("hello, I am child (pid:%d)\n", (int) getpid());
//     } else {
//         // parent goes down this path (main)
//         printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
//     }
//     return 0;
// }


// int main(int argc, char *argv[]) {
//     printf("hello world (pid:%d)\n", (int) getpid());
//     int rc = fork();
//     if (rc < 0) { // fork failed; exit
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) { // child (new process)
//         printf("hello, I am child (pid:%d)\n", (int) getpid());
//     } else { // parent goes down this path (main)
//         int rc_wait = wait(NULL);
//         printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",
//                rc, rc_wait, (int) getpid());
//     }
//     return 0;
// }

// int main(int argc, char *argv[]) {
//     printf("hello world (pid:%d)\n", (int) getpid());
//     int rc = fork();
//     if (rc < 0) { // fork failed; exit
//         fprintf(stderr, "fork failed\n");
//         exit(1);
//     } else if (rc == 0) { // child (new process)
//         printf("hello, I am child (pid:%d)\n", (int) getpid());
//         char *myargs[3];
//         myargs[0] = strdup("wc"); // program: "w3" (word count)
//         myargs[1] = strdup("p3.c"); // argument: file to count
//         myargs[2] = NULL; // marks end of array
//         execvp(myargs[0], myargs); // runs word count
        
//         printf("this shouldn't print out");
//     } else { // parent goes down this path (main)
//         int rc_wait = wait(NULL);
//         printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",
//                rc, rc_wait, (int) getpid());
//     }
//     return 0;
// }

int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child: redirect standard output to a file
        close(STDOUT_FILENO);
        open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

        // now exec "wc"...
        char *myargs[3];
        myargs[0] = strdup("wc"); // program: wc (word count)
        myargs[1] = strdup("p4.c"); // arg: file to count
        myargs[2] = NULL; // mark end of array
        execvp(myargs[0], myargs); // runs word count
    } else {
        // parent goes down this path (main)
        int rc_wait = wait(NULL);
    }
    return 0;
}
