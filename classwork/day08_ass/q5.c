/*
logic for incrementing squared number-start pattern
*/
#include<stdio.h>
int main()
{
	int n,num,i,j;
	printf("Entern the n value: \n");
	scanf("%d",&n);
	num=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d",num);
			num++;
			if(j<n)
				printf("*");
		}
		printf("\n");
	}
}
