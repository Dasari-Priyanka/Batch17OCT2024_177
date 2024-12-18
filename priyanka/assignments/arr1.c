#include<stdio.h>
#define MAX 100
int getmax(int arr[], int size)
{
	int max,i;
	max = arr[0];
	for(i=1;i<size; i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	return max;
}
int main()
{
	int arr[]={11,22,33,44,55};
	int size = 5;
	int max=getmax(arr,size);
	printf("max value in the array: %d\n",max);
	return 0;
}
