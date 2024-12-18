#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int i;
	printf("\nNo of args: %d\n",argc);

	for(i=0;i<argc;i++)
	{
		printf("%s\n",argv[i]);
	}
	return 0;
}
