#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

#define PERMS 0666
#define MAXBUF 1024


int main()
{
    int semid,nsem=0;
	key_t key= ftok("/home2/user79/Batch17OCT2024_509/classwork/day24",79);
	nsem=1;

    semid = semget(key,nsem,PERMS|IPC_CREAT);


    if(semid < 0)
    {
        perror("semget()");
        exit(EXIT_FAILURE);
    }
	printf("Semaphore is created with ID %d",semid);
	printf("\n\n");



    return 0;
}

