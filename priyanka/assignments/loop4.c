#include<stdio.h>
#include <gmp.h>
int main()
{
        mpz_t fact=1;
        int count,num;
        printf("Enter a number:");
        scanf("%d",&num);
        for(count = 1;count <= num;count++)
        {
                fact = fact * count;
        }
        printf("factorial of %d is :%Zd \n",num,fact);
        return 0;
}
