#include<stdio.h>

int main()
{
	int i,n,j;
	int sum;
	int add=0;
	int arr[20];
	int count=0;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	printf("\nEnter array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d",&sum);
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{   
			
			add=arr[i]+arr[j];
			if(add==sum)
			{
				printf("sum of index %d and %d\n",i,j);
				count++;
			}
		}
	}
	if(count==0)
	 printf("NO subarray\n");
	 
	return 0;


}
