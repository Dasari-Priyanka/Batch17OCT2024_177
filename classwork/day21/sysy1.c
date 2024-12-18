#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	long int i;
	int pid = getpid();
	pid_t ppid = getppid();
	printf("\nMy own Pid =%d\n",pid);
	printf("\nparent Ppid =%d\n",ppid);
	printf("\n\n");
	return 0;

}
