#include<stdio.h>
#include<string.h>
#define MAX 20
void palindrome(char *[]);
int main()
{
	int i;
	char str1[MAX];
	printf("Enter the string\n");
	fgets(str1,MAX,stdin);
	str1[strlen(str1)-1]='\0';
	palindrome(str1);


	return 0;
}
void palindrome(char *str1[])
{
	int len,i;
	len=strlen(str1);
	for(i=0;i<len;i++)
	{
		if(str1[i]==str1[len-i-1])
			continue;

			printf("not palindrome\n");
	}
	printf("palindrome\n");
}

