#include<stdio.h>
#include<string.h>
int main()
{
	 char str[100];
	 printf("Enter a string:\n");
	 fgets(str,sizeof(str),stdin);
	 reverseStr(str);
	 printf("Reversed string is: %s\n",str);
	 return 0;
}
void reverseStr(char str[])
{
int length = strlen(str);

}
