#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 80
int write(FILE *fptr, char *line);
int read(FILE *fptr, char *linebuf);

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        puts("Less or more arguments than required");
        return 1;
    }

    if(strlen(argv[1])>MAX || strlen(argv[2])>MAX)
    {
        puts("String length should less than 80");
        return 0;
    }

    char linebuf[MAX+1];
    char *ch;
    FILE *fd=NULL;
    fd=fopen("test.txt","w");
    if(fd==NULL)
    {
        perror("fopen: ");
        return 0;
    }
    if(write(fd,argv[1])<0 || write(fd,argv[2])<0)
    {
        puts("Failed to write in file");
        return 0;
    }
    fclose(fd);

    fd=fopen("test.txt","r");
    if(fd==NULL)
    {
        perror("fopen: ");
        return 0;
    }
	ch=linebuf;

    while(read(fd,ch)==0)
    {
        puts(linebuf);
    }
    fclose(fd);
    return 0;
}

int write(FILE *fptr, char *line)
{
    if(fprintf(fptr,"%s\n",line)<0)
    {
        return -1;
    }

    return 0;
}

int read(FILE *fptr, char *linebuf)
{
    if(fptr==NULL || linebuf ==NULL)
    {
        return -1;
    }
    if(fgets(linebuf,MAX,fptr)==NULL)
    {
        return -1;
    }
    return 0;
}

