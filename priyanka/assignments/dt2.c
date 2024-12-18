#include<stdio.h>

int main()
{
	char choice;
	printf("Enter your choice(y/Y for yes, n/N for No\n");
	scanf("%c",&choice);
	if(choice=='y'|| choice=='Y')
		printf("Yes\n");
	else if(choice=='n'||choice=='N')
		printf("No\n");
	else
		printf("Invalid character\n");
	
	return 0;
}
