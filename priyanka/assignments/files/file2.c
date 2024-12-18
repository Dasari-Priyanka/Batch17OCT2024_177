#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int files(char *[]);
int read_and_write(FILE *,FILE *,FILE *);
int main(int argc,char *argv[])
{
    if(argc!=4)
    {
        puts("less or more than required arguments");
        return 1;
    }
    files(argv);
	int files(char *[]);
    int read_and_write(FILE *,FILE *,FILE *);

    return 0;
}
int files(char *input[])
{
    FILE *fd1=NULL;
    FILE *fd2=NULL;
    FILE *fout=NULL;
    fd1=fopen(input[1],"r");
    fd2=fopen(input[2],"r");
    fout=fopen(input[3],"w");
    if(fd1==NULL || fd2==NULL ||fout==NULL)
    {
        perror("fopen: ");
        exit(1);
    }

    read_and_write(fd1,fd2,fout);
    fclose(fd1);
    fclose(fd2);
    fclose(fout);
    return 0;
}
int read_and_write(FILE *fd1,FILE *fd2,FILE *fout)
{
    int line1;
    char line2[MAX];
    while(fscanf(fd1,"%d",&line1)==1 && fgets(line2,MAX,fd2)!=NULL)
    {
        fprintf(fout,"%d %s",line1,line2);
    }
    return 0;
}

