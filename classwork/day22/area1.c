#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[], char *envp)
{
	int i;
	char *temp;
	for(i=0;envp[i];i++)
	{
		printf("\nfound");
	}
	printf("\n\n");

	return 0;
}
