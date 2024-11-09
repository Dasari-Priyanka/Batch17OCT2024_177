/*
prblm stmt: I taste is good eat until stomach is full and plate is empty
*/
#include <stdio.h>
int main()
{
	char taste='g';
	int emptyPlate=10;
	int sFull=0;
	do
	{
		printf("\nHave a bite of food\n");
		emptyPlate --;
		printf("\nstomach Full (1/0): ");
		scanf("%d",&sFull);
		printf("\nHow was the taste (g/b): ");
		scanf(" ");
		taste = getchar();
		printf("\nEmpty Plate value: %d",emptyPlate);
	}while((taste=='g') && (sFull==0) && (emptyPlate>=0));
	printf("\nProgram End\n");
	return 0;
}
