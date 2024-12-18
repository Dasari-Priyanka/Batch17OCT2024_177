#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main()
{
	int msgid;
	msgid=msgget((key_t)1002,IPC_CREAT|IPC_EXCL|0644);
	printf("\nMSG queue created with %d id\n",msgid);
	printf("\n\n");
	return 0;
}
