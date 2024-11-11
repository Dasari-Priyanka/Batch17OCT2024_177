#include<stdio.h>
int main()
{
	int arr[10];
	int	n=2;
	int i=1,j=0;
	do{
		arr[j]=n*i;
		printf("\n%d*%d=%d\n",n,i,arr[j]);
		i++;
	}while(i<=10);
}
