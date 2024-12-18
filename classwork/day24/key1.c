#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main()
{
	key_t key =ftok("/home2/user79/Batch17OCT2024_509/classwork/day24",10010);
	printf("\n%X",key);
	printf("\n\n");
	return 0;
}
