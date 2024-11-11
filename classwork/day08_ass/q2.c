/*
print sreies 1, 2, 4, 8, 16, 32, 64.
*/
#include <stdio.h>
int main()
{
	int n,itr,num;
	num=1;
	printf("\nEnter the value: \n");
	scanf("%d",&n);

	
	
	for(itr =0; itr<n;itr++)
	{
		
		
		printf("%d, ",num);
		num*=2;

	}

	printf("%d.\n",(itr*itr)-1);
	return 0;
}
