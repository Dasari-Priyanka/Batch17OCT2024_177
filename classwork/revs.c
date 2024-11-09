#include <stdio.h>
#include <string.h>
void reverse(char str);
int main()
{
	int k,ret;
	char str[10];
	char *ptr = NULL;
	printf("\nEnter the string\n");
	scanf("[^\n]%s",str);
	printf("\nEnter revser value\n");
	scanf("%d",&k);
	ret = reverse(char str);
	printf("%s",ret);
	return 0;
}





void reverse(char str)
{
	int i,j,temp;
	int len=strlen(str);
	for(i=0;i<len;i++)
	{
		temp = str[i];
		str[i]=str[i+1];
		str[i+1]=temp;
	}
	return str
		

		
			
}


