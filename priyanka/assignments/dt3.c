#include<stdio.h>
int main()
{
	int decimal;
	printf("Enter a decimal number(0-127):\n");
	scanf("%d",&decimal);
	if(decimal<0||decimal>127)
		printf("Invalid number\n");
	else
		printf("The hexadecimal representation is: %02X\n",decimal);
	
	return 0;
}
