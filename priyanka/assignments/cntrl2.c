#include<stdio.h>
int main()
{
	char ch;
	printf("Enter the designation code as 2,3,4,5:\n");
	scanf("%c",&ch);
	switch(ch)
	{
	case '2': 
		printf("Software Developer\n");
		break;
	case '3':
		printf("Senior Software Developer\n");
		break;
	case '4':
		printf("Team Lead\n");
		break;
	case '5':
		printf("Senior Team Lead\n");
		break;
	default:
		printf("incorrect designation code\n");
		break;
	}
}
