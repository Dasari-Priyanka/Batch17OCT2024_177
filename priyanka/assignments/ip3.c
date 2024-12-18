#include<stdio.h>
void display(char *);
int main()
{
   char arr[]="hello hi";
   char *ptr = arr;

   printf("sizeof ptr:%lu, arr:%lu\n", sizeof(ptr), sizeof(arr));
   display(ptr); 
   return 0;
}

void display(char *ptr)
{
    printf("Address of ptr: 0x%x\n",(unsigned int)ptr);
    printf("Contents: %s\n", ptr);
}
