#include<stdio.h>
int main()
{
	int fd[2];
	pid_t cpid;
	char line[buff];
	pipe(fd);
	cpid=fork;
	if(cpid == 0)
	{
		close(fd[0]);
		write(fd[1],"Hello World\n",12);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]);
		read(fd[0],line,BUFF);
		printf("\nLine Read\n%s",line);
	}
	printf("\nEnd of the program\n");
	return 0;
}
