#include<stdio.h>
#include<string.h>

#define ROWS 3
#define COLS 3

int init(char arr[ROWS][COLS])
{
	strcpy(arr[0],"AaB");
	strcpy(arr[1],"CcD");
	strcpy(arr[2],"DdD");
	return 0;
}
int search_update(char arr[ROWS][COLS], char oldValue[], char newValue[])
{
	for(int i=0;i<ROWS;i++)
	{
		if(strcmp(arr[i],oldValue)==0)
		{
			strcpy(arr[i],newValue);
			return 0;
		}
	}
	return 1;
}
void display(char arr[ROWS][COLS])
{
	for(int i=0;i<ROWS;i++)
		printf("%s\n",arr[i]);
}
int main()
{
	char arr[ROWS][COLS];
	char oldValue[]="CcD";
	char newValue[]="XxY";
	int result=search_update(arr,oldValue,newValue);
	if(result==0)
		printf("Updated array after chaning %s to %s :\n",oldValue,newValue);
	else
		printf("Element %s not found.\n",oldValue);
	display(arr);
	return 0;
}
