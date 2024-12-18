#include "myheader.h"
#define PERMS 0666
#define MAXBUF 1024
typedef struct Employee
{
	int id;
	int sal;
	char name[MAXBUF];
}EMP;
int main()
{
	key_t key = 79;
	EMP *e=NULL;
	int shmid;
	char *msg;
	shmid=shmget(key,sizeof(EMP)*1,PERMS|IPC_CREAT);
	if(shmid<0)
	{
		perror("shmget()");
		printf("\nDirectly use this shm mem to read &write");
		exit(EXIT_FAILURE);
	}
	printf("\nShared mem id = %d\n",shmid);
	e=(EMP *)shmat(shmid,(void *)0,0);
	printf("\nEnter EMP details\n");
	printf("\nNAME: ");
	scanf("%[^\n]s",e->name);
	printf("\nID: ");
	scanf("%d",&e->id);
	printf("\nSalary: ");
	scanf("%d",&e->sal);
	shmdt(e);

	return 0;
}
