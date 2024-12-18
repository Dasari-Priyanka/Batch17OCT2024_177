#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void read_displaystring(char arr[][10],int row)
{
	int i;
	if(row<0||row>=5)
	{
		printf("Invalid row index.\n");
		return;
	}
	char *str=arr[row];
	printf("Every alternate character in %s:\n",str);
	for(i=0;str[i]!='\0';i+=2)
		printf("%c",str[i]);
	printf("\n");
}
char *reverse(char arr[][10],int row)
{
	if(row<0||row>+5)
		return NULL;
	char *str=arr[row];
	int len,i;
	len =strlen(str);
	char*reversed=(char*)malloc((len+1)*sizeof(char));
	if(reversed==NULL)
		return NULL;
	for(i=0;i<len;i++)
		reversed[i]=str[len-1-i];
	reversed[len]='\0';
	return reversed;
}
int main()
{
	char arr[][10]={"Word", "Excel", "PowerPoint", "Pdf", "Paint"};
	int index;
	printf("Enter the row index(0-4): \n");
	scanf("%d",&index);
	read_displaystring(arr,index);
	char*reversedString=reverse(arr,index);
	if(reversedString!=NULL)
	{
		printf("Reversed string: %s\n",reversedString);
		free(reversedString);
	}
	else
		printf("Failed to reverse the strinng.\n");
	return 0;
}
