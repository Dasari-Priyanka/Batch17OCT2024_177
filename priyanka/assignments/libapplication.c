//libapplication.c
#include <stdio.h>
#include <cal_utility.h>

int main()
{
	int a =5, b=10;
	int sum = add(a,b);
	int difference = subtract(a,b);

	printf("Sum: %d\n",sum);
	printf("Difference: %d\n",difference);

	return 0;
}
