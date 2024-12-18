#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	printf("\nIn execl\n");
	execl(argv[1],argv[2],argv[3],(char*)0);
	
	return 0;
}
