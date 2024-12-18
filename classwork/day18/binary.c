#include<stdio.h>

int binarySearch(int [] , int);
#define CAP 10
int main()
{
	int arr[CAP];
	int res,key,n,i;
	printf("Enter the array\n");
	for(i=0;i<CAP;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter a key\n");
	scanf("%d",&key);
	res=binarySearch(arr,key);
	if(res==1)
	{
		printf("Found\n");
	}
	else
		printf("Not Found\n");
	return 0;
}
int binarySearch(int arr[], int key)
{
	int low,high,mid,flag;
	flag=0;
	low=0;
	high=CAP;
	while(low<=high)
	{
		mid=(arr[low]+arr[high])/2;
		if(key==arr[mid])
		{
			flag =1;
			break;
		}
		else if(key>arr[mid])
		{
			low=mid+1;

		}
		else
		{
			high=mid-1;
		}
	}
	return flag;
}
