#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
typedef struct book
{
	char title[MAX];
	char autor[MAX];
	char genre[MAX];
}BOOK;
void display(BOOK *, int );
void sort(BOOK *, int );

int main()
{
	int N,i;
	BOOK *b =NULL;
	printf("Enter the no of books\n");
	scanf("%d",&N);
	b = (BOOK *)malloc(N*sizeof(BOOK));
	printf("Enter the book details\n");
	for(i=0;i<N-1;i++)
	{
		printf("Enter title of book\n");
		fgets(b[i].title,MAX,stdin);
		b[i].title[strlen(b[i].title)-1]='\0';
		printf("Enter autor of book\n");
		fgets(b[i].autor,MAX,stdin);
		b[i].autor[strlen(b[i].autor)-1]='\0';
		printf("Enter genre of book\n");
		fgets(b[i].genre,MAX,stdin);
		b[i].autor[strlen(b[i].autor)-1]='\0';
	}
	sort(b,N);
	display(b,N);

}
void sort(BOOK *b, int N)
{
	int i,j;
	char temp[MAX];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(strcmp(b[j].genre,b[j+1].genre)>0)
			{
				strcpy(temp,b[j].genre);
				strcpy(b[j].genre,b[j+1].genre);
				strcpy(b[j+1].genre,temp);
			}
		}
	}
}
void display(BOOK *b, int N)
{

	int i;
	for(i=0;i<N;i++)
	{
		printf("%s",b[i].title);
	}
}
