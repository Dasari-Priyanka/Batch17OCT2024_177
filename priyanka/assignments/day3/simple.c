#include<stdio.h>
int main()
{
	char name[100];
	printf("Enter your name: ");
	scanf("%s",name);
	printf("%s",name);
	if(cmpstr(name,mumbai)==0);
		printf("Equal");
	else
		printf("not equal");
	return 0;
}
