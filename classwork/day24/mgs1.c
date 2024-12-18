#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define PERMS 0666

typedef struct msgText
{
	long msgtype;
	char txtMsg[1024];
}
int main()
{
	
}

