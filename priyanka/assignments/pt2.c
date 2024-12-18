#include<stdio.h>
#include<string.h>
#define MAX 100
#define SUCCESS 1
#define FAILURE 0
int search_insert(char name[], char search_char,char insert_char);

int main()
{
	char name[MAX]="ABC";
	char *ptr = name;
	char search_char ='B';
	char insert_char = '_';
	int ret = search_insert(name, search_char,insert_char);

    if (ret == SUCCESS)
	{
		printf("Updated string: %s\n",name);	
	}
	else
		printf("Character %c not found.\n",search_char);
	return 0;
}
int search_insert(char name[], char search_char,char insert_char)
{
	int len,i,j;
	len = strlen(name);
	for(i=0;i<len;i++)
	{
		if(name[i]==search_char)
		{
			for(int j=len;j>i;j--)
				name[j+1]=name[j];
		
			name[i+1]=insert_char;
			name[len+1]='\0';
			return SUCCESS;
		}

	}
	return FAILURE;

}
