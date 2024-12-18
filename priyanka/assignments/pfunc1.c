#include<stdio.h>

int *func(void);

int main()
{
    int num, *ptr = NULL;
    ptr = func();  // No need to cast since the return type is already int*
    num = *ptr;
    printf("%d\n", num);  // Printing the value to verify
    return 0;
}

int *func()
{
    static int local;  // 'local' will persist after the function exits
    local = 10;
    return &local;  // Return the address of the static variable
}

