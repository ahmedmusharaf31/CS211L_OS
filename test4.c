/* args.c */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
int i;
for(i=0;i<argc;i++)
{
printf("&argv[%d] = %p \n",i,&argv[i]);
}

printf("---------------------------\n");
for(i=0;i<argc;i++)
{
printf("argv[%d]= %p \n",i,argv[i]);
}

printf("---------------------------\n");
for(i=0;i<argc;i++)
{
printf("*argv[%d]= %c \n",i,*argv[i]);
}
return 0;
}
