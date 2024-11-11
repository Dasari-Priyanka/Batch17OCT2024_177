/*
print the start pattern
*
**
***
****
*****
*/
#include<stdio.h>
int main()
{
	int i,j,n;
	printf("Enter the n value:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
			printf("*");
		printf("\n");
	}
	
}
