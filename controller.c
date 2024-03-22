#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
if(argc!=3)
{
fprintf(stderr,"Usage: %s <testrun1.txt> <testrun2.txt>",argv[0]);
exit(2);
}

if(strcmp(argv[1],argv[2])==0)
{
fprintf(stderr,"Error! Both files have the same name \n");
exit(2);
}

int pid=fork();
if(pid<0)
{
perror("fork");
exit(2);
}

else if(pid==0)
{
execl("./worker","worker",argv[1],argv[2],NULL);

// If execl fails, print an error message
perror("execl");
exit(2);
}

else
{
printf("Worker process executed with PID: %d \n",(int) getpid());
int status;

// Wait for child process to finish
waitpid(pid,&status,0);

if(WIFEXITED(status))
{
int exit_status=WEXITSTATUS(status);

if(exit_status==0)
{
printf("Worker process with PID %d has finished. Both files are the same!\n",(int) getpid());
}
else if(exit_status==1)
{
printf("Worker process with PID %d has finished. Both files are different!\n", (int) getpid());
}
else
{
printf("Worker process with PID %d has finished. Error opening files!\n",(int) getpid());
}
}

else
{
printf("Worker process with PID %d has finished abnormally!\n",(int) getpid());
}
}

exit(0);
}