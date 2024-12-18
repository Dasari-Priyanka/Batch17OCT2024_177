/*
1.	WAP to read a number n and to display the cumulative sum of  factorial of all numbers  upto n . (use for or while)
Input: 4
Ouput: 4!+3!+2!+1! = 32
*/
#include <stdio.h>

int factorial(int num) 
{
    int fact = 1;
    for (int i = 1; i <= num; i++) 
        fact *= i;
    return fact;
}

int main()
{
    int n, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--) 
        sum += factorial(i);

    printf("The cumulative sum of factorials from %d! to 1! is: %d\n", n, sum);

    return 0;
}
