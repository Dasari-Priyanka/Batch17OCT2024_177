#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	printf("\nec2.c\n");
	printf("\nPID: %d",getpid());
	printf("\nHello %s,\nWelcom to programming\n",argv[1]);
}
