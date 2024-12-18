#include <stdio.h>
#include "linking2.c"
int main()
{
    int num1,num2;
    printf("\nEnter num1 and num2: ");
    scanf("%d%d",&num1,&num2);
    printf("\nMultiplication of numbers: %d",mul(num1,num2));
    printf("\nDivision of numbers: %f",div(num1,num2));
    return 0;
}

