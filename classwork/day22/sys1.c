#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	 printf("\nThis is sPrg04\n");
	 if(fork()>0)
	 {
	 	wait(0);
		printf("\nsprg04 PID:%d", getpid());
	 }
	 else
	 {
	 	execl("/bin/ls","/bin/ls",(char *)0);
	 }
	 printf("\nEnding sPrg04\n");
	 printf("\n\n");
	 return 0;
}
