#include<stdio.h>
#define CAP 5
#define True 1 
int swap(int *, int *);
int bubbleSort(int []);
int selectionSort(int []);
void display(int []);
int insertionSort(int []);
int main()
{
	int arr[CAP],i;
	for(i=0;i<CAP;i++)
		scanf("%d",&arr[i]);
	bubbleSort(arr);
	display(arr);
 	selectionSort(arr);	
	display(arr);
	insertionSort(arr);
	display(arr);

	return 0;
}
void display(int arr[])
{
	int i;
	for(i=0;i<CAP;i++)
		printf("%d ",arr[i]);
	printf("\n\n");
}
int selectionSort(int arr[])
{
	int i,min_i,j,flag;
	for(i=0;i<CAP;i++)
	{
		min_i=i;
		flag=0;
		for(j=i+1;j<CAP-i;j++)
		{
			if(arr[i]>arr[j])
			{
				min_i=j;
				flag=1;
			}
		}

		if(flag=1)
			swap(&arr[i],&arr[min_i]);
	}
	return True;
}
int bubbleSort(int arr[])
{
	int i,j;
	for(i=0;i<CAP;i++)
	{
		for(j=0;j<CAP-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}

		}
	}
	return True;

}
int swap(int *arr1, int *arr2)
{
	int temp;
	temp=*arr1;
	*arr1=*arr2;
	*arr2=temp;

}
int insertionSort(int arr[])
{
	int i,j,key;
	for(i=1;i<CAP;i++)
	{
		key=arr[i];
		for(j=i-1;j>=0 && key<arr[j];j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=key;
	}
	return True;
}
