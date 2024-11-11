#include <stdio.h>
#include <string.h>
void revers(char []);
int main()
{
	char str[100];
	int length;
	length= strlen(str)-1;
	printf("\nEnter the string\n");
	scanf("[^\n]%s",str);
	revers(str);
	printf("%s",str);
	return 0;
}
void revers(char str[])
{
	int i;
	char temp;
	int length;
	printf("len:%d\n",length);
	while(i<length)
	{
		temp = str[i];
		str[i]=str[length];
		str[length]=temp;
		printf("%s\n",str);

		i++;
		length--;
	}
	
     		

		
			
}


