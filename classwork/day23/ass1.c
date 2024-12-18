#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#define PI 3.14

void display();
void areaRectangle();
void areaCircle();
void signalhandle(int id);
void signalhandle(int id)
{
	static int interrupted = 0;
    if (interrupted == 0) 
	{
        printf("\nInterrupted by signal: %d\n", id);
        interrupted = 1; 
	}
}

int main()
{
	int status=0;
    signal(SIGINT, signalhandle);
    signal(SIGQUIT, signalhandle);
    signal(SIGTERM, signalhandle);
    if(fork() == 0)
	{
		while(1);
        	exit(EXIT_SUCCESS);
    }
 	else
    {
		wait(&status);
        printf("Parent died: status : %d\n",status/256);
    }

	return 0;
}
void display()
{
	int ch;
	printf("\nMenu:\n");
    printf("1. Calculate Area of Rectangle\n");
    printf("2. Calculate Area of Circle\n");
    printf("0. Exit\n");
    
    printf("Enter your choice: ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			areaRectangle();
			break;
		case 2:
			areaCircle();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("\nInvalid inputs\n");
			break;
			
	}
}
void areaRectangle()
{
	int l,b,Area;
	printf("\nEnter the length of rectangle:\n");
	scanf("%d",&l);
	printf("\nEnter the breadth of rectangle:\n");
	scanf("%d",&b);
	Area=l*b;
	printf("%d",Area);

}
void areaCircle()
{
	int r,Area1;
	printf("Enter the radius of circle:\n");
	scanf("%d",&r);
	Area1=PI*r*r;
	printf("%d",Area1);
}
