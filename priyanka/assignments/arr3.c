#include<stdio.h>
void sort(char arr[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				char temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
int main()
{
	 char arr[]="xaybz";
	 int strlen=(sizeof(arr)/sizeof(arr[0]))-1;
	 sort(arr,strlen);
	 printf("sorted array: %s\n",arr);
	 return 0;
}
