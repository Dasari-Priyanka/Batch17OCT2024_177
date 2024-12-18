#include <stdio.h>

char *my_strncat(char *test, const char *src, size_t n);

int main() {
    char test[100] = "Hello, ";
    char src[] = "World!";

    my_strncat(test, src, 3);

    printf("Resulting String: %s\n", test);  

    return 0;
}

char *my_strncat(char *test, const char *src, size_t n)
{
    char *test_ptr = test;
    while (*test_ptr != '\0')
	{
        test_ptr++;  
    }

    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) 
	{
        test_ptr[i] = src[i];  
    }

    test_ptr[i] = '\0';

    return test;  
}
