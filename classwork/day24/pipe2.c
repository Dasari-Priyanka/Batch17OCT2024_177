#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#define buff 1024
int main()
{
    int fd[2];
    pid_t cpid;
    char line[buff];
    pipe(fd);
    cpid=fork();
    if(cpid == 0)
    {
        close(fd[1]);
        read(fd[0],line,buff);
		printf("\nRead LInes\n%s",line);
    }
    else
    {
        close(fd[0]);
        write(fd[1],"HELLO WORLD\n",12);
        exit(EXIT_SUCCESS);
    }
    printf("\nEnd of the program\n");
    return 0;
}

