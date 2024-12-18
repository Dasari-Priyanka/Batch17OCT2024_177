#include<stdio.h>
#include<string.h>
typedef struct Employee{
	int id;
	int phno;
	int sal;
	char Name[10];
	char Gender;
	}EMP;
int printEMP(EMP *);
int getEMP(EMP *);
int main()
{
	EMP e;
	char *ptr=NULL;
	FILE *fd=NULL;
	char ch;
	fd=fopen("db.txt","r");
	if(fd== NULL)
	{
		perror("fopen: ");
		return 1;
	}
	while((ptr=strtok(NULL,"|"))!=EOF)
	{
		getEMP(*ptr);
		
	}
	printEMP(*ptr);
}

int getEmp(EMP *e)
{
	printf("\nEnter the Employee Details\n");
    scanf("%d%d%d",&e->id,&e->sal,&e->phno);
    scanf("%s",e->Name);
    getchar();
    scanf("%c",&e->Gender);
}
int printEmp(EMP *e)
{
	 printf("\nEmployee Details are\n");
     printf("\n===============================\n");
	 printf("\nID: %d",e->id);
     printf("\nName: %s",e->Name);
     printf("\nGender: %c",e->Gender);
     printf("\nPhNo: %d",e->phno); 
	 printf("\nSalary: %d",e->sal);
     printf("\n===============================\n");



}
