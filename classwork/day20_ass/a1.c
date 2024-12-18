#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sort(char ***,int );
int main()
{
	int i,j,k,N,r,c;
	scanf("%d",&N);
	r=3,c=50;
	char ***books=NULL;
	books=(char ***)malloc(N*sizeof(char **));
	for(i=0;i<N;i++)
	{
		books[i]=(char **)malloc(r*sizeof(char *));
	
		for(j=0;j<r;j++)
		{	
			books[i][j]=(char *)malloc(c*sizeof(char));
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("Enter the book:\n");
			scanf(" ");
			scanf("%s",books[i][j]);
		}
	}
	sort(books,N);
	for(i=0;i<N;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("After sorting\n");
			printf("%s\n",books[i][j]);
		}
	}
}
void sort(char ***books,int N)
{
	int i,j;
	char *t;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N-i-1;j++)
		{
			if(strcmp(books[i][j],books[i][j+1])>0)
			{
				strcpy(t,books[i][j]);
				strcpy(books[i][j],books[i][j+1]);
				strcpy(books[i][j+1],t);
			}
		}
	}
}

