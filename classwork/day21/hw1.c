#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int id,id1,id2;
	printf("\nI am in main\n");
	printf("child pid:%d\n",getpid());
	printf("parent ppid:%d\n",getppid());
	id=fork();
	if(id<0)
	{
		printf("\nid not created\n");
	}
	else if(id==0)
	{
		printf("\ni am in child1\n");
		printf("child pid:%d\n",getpid());
		printf("child id:%d\n",id);
		id1=fork();
		if(id1==0)
		{
			printf("\nI am in child1-child\n");
			printf("child pid:%d\n",getpid());
			printf("child id:%d\n",id1);
		}
		else
		{
			wait(0);
			printf("\nI am in child1-parent\n");
			printf("parent ppid:%d\n",getppid());
			printf("child pid:%d\n",getpid());
			printf("parent id:%d\n",id1);
		}
	}
	else
	{
		wait(0);
		printf("\nI am in parent1\n");
		printf("parent ppid:%d\n",getppid());
		printf("parent id:%d\n",id);
		id2=fork();
		if(id2==0)
		{
			printf("\nI am in parent1-child\n");
			printf("child pid:%d\n",getpid());
			printf("child id:%d\n",id2);
		}
		else
		{
			wait(0);
			printf("\nI am in parent1-parent\n");
			printf("parent ppid:%d\n",getppid());
			printf("parent id:%d\n",id2);
			printf("child pid:%d\n",getpid());
		}
	}
	printf("\nhelloworld\n");
	return 0;

}
