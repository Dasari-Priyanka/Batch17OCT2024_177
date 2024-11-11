/*
print the sum of 1+4-9+16-25+36
*/
#include<stdio.h>
int main()
{
	 int n,sum,i,term;
	 printf("Enter the number of terms(n):\n");
	 scanf("%d",&n);

	 for(i=1;i<n;i++)
	 {
	 	term=i*i;
		if(i%2==0)
		{
			sum+=term;
			printf("%d+",term);
		}
		else
		{

			sum-=term;
			printf("%d-",term);
		}
	 }
	 if(i==n)
	 {
	 	term=i*i;
		printf("%d \n",term);
	 }
	 printf("The sum of the series for %d term is: %d\n",n,sum);
}
