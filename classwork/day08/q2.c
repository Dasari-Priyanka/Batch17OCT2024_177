#include <stdio.h>
int main()
{
	int n,itr,t1,t2,t3;
	printf("\nEnter the value: \n");
	scanf("%d",&n);
	t1=0;
	t2=1;
	
	
	for(itr =n; itr<0;itr++)
	{
		t3=t1+t2;
		
		printf("%d, ",t3);
		t1=t3;
		t2=t3;

	}
	return 0;
}
