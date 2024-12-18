#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	int l,b;
	l=atoi(argv[1]);
	b=atoi(argv[2]);
	
	printf("%d",l*b);
}

