#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define Max_Length 1024

int main(int argc,char *argv[])
{
// Error opening files
if(argc!=3)
{
fprintf(stderr,"Usage: %s <testrun1.txt> <testrun2.txt>\n",argv[0]);
exit(2);
}

if(strcmp(argv[1],argv[2])==0)
{
fprintf(stderr,"Error! Both file names are the same \n");
exit(2);
}

FILE *file1=fopen(argv[1],"r");
FILE *file2=fopen(argv[2],"r");

if(file1==NULL || file2==NULL)
{
perror("fopen");
exit(2);
}

char c1[Max_Length],c2[Max_Length];
int result=1;
while(!feof(file1) && !feof(file2)){
fgets(c1, Max_Length, file1);
fgets(c2, Max_Length, file2);
if(strcmp(c1, c2) != 0){
result=0;
break;
}
}

// Both files are the same
if(result)
{
printf("Both files are the same!\n");
fclose(file1);
fclose(file2);
exit(0);
}

// Both files are different
else
{
printf("Both files are different!\n");
fclose(file1);
fclose(file2);
exit(1);

}
}