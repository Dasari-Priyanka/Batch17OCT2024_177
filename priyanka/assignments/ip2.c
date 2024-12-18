#define MAX 100
#define SUCCESS 0
#define FAILURE 1
#include<stdio.h>
int append(char *, char *);
void display(char *); 

int main()
{
   char arr[MAX] = "Learning C";
   char*ptr = arr;
   char appendstr[50]= "in my org";

   printf("Address of ptr:%p", ptr);
  
   int ret = append(ptr, appendstr);// append the string 

   printf("Address of ptr:%p", ptr);

   if (ret == SUCCESS)
   {
       display(ptr); // display the address in hex and contents using pointer
   }
}
int append(char *ptr, char *appendstr)
{
    while (*ptr != '\0') {
        ptr++;  
    }

    while (*appendstr != '\0')
	{
        *ptr = *appendstr;  
        ptr++;  
        appendstr++;  
    }

    *ptr = '\0';

    return SUCCESS;
}

void display(char *ptr) {
    printf("Address of ptr: %p\n", ptr);
    printf("Contents: %s\n", ptr);        
}

	

