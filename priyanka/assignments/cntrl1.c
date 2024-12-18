#include<stdio.h>
int main()
{
	int n1,n2,n3,res;
	printf("Enter 3 numbers:\n");
	scanf("%d%d%d",&n1,&n2,&n3);
	res = (n1<n2)?((n1<n3)?n1:n3):((n2<n3)?n2:n3);
	printf("smallest number is %d\n",res);
}
