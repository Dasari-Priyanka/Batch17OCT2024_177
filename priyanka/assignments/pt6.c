#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[]="ABC";
	
	char *ptr = (char*)&arr;
	printf("%p %p", arr, ptr);
	printf("\n 1 %c %c", *ptr, *(ptr+1));
	
    char msg[][5] = {"AB", "gh", "er"};
	char (*ptr2)[5];
	
	ptr2 = msg;
	printf("%p %p",(void*)msg,(void*)ptr2);
	printf("\n 2 %c %c", (*ptr2)[0], (*ptr2)[1]);
	
}
