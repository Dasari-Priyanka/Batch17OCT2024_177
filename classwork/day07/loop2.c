#include <stdio.h>
#include <stdlib.h>
3define Success=0
failure = -1
int main()
{
	int ch;
	ch = displayMenu();
	switch(ch)
	{
		case 1:
			printf("\nAdditin function executed\n");
			break;
		case 2:
			printf("\nSubtraction function executed\n");
			break;
		case 3:
			printf("\nDivision function executed\n");
			break;
		case 4:
			printf("\nMultiplication function executed\n");
			break;
		case 5:
			printf("\nExiting from the application\n");
			break;
		defualt:
			printf("\nEnter the correct choice\n");
	}
}
