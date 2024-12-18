#include<stdio.h>
#define MAX 100
void init(int arr[], int N, int start)
{
	int i;
	for(i=0;i<N;i++)
	{
		arr[i]=start+i;
	}

}
void update(int arr[], int N)
{
	int i;
	for (int i=0; i<N;i++)
		printf("%d", arr[i]);
}
void display(int arr[], int N)
{
	int i;
	for(i=0;i<N;i++)
		printf("%d",arr[i]);
	printf("\n");
}
int main()
{
	int arr[MAX];
	int N,start;
	printf("Enter the numbet of elements:\n");
	scanf("%d",&N);
	printf("enter the start value: ");
	scanf("%d",&start);
	init(arr,N, start);
	update(arr,N);
	display(arr,N);
	return 0;
}
