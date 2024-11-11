/*
demo of structure
*/
#include<stdio.h>
#include <string.h>
struct Employee
{
	char eName[20];
	char eGender;
	char eAddress[20];
	int eId;
	float eSal;
};
typedef struct Employee EMP;
int main()
{
	int i;
	EMP e1;
	EMP e[3];

	e1.eId =101;
	e1.eSal = 10000.1;
	strcpy(e1.eName,"Priya");
	strcpy(e1.eAddress,"Andhra");
	e1.eGender ='F';

	printf("\nEmployee Details are\n");
	printf("\nID: %d",e1.eId);
	printf("\nName: %s",e1.eName);
	printf("\nGender: %c",e1.eGender);
	printf("\nAddress: %s",e1.eAddress);
	printf("\nSalary: %f",e1.eSal);
	printf("\n\n");

	
	printf("\nEnter Employee Details\n");
	for(i=0;i<3;i++)
	{
		printf("\nName: ");
		scanf("%d",&e[i].eName);
		printf("\nId: ");
		scanf("%d",&e[i].eId);
		printf("\nGender: ");
		scanf("%d",&e[i].eGender);
		printf("\nAddress: ");
		scanf("%d",&e[i].eAddress);
		printf("\nSalary: ");
		scanf("%d",&e[i].eSal);
    }
	for(i=0;i<3;i++)
	{
	printf("\nEmployee Details are\n");
	printf("\nID: %d",e[i].eId);
	printf("\nName: %s",e[i].eName);
	printf("\nGender: %c",e[i].eGender);
	printf("\nAddress: %s",e[i].eAddress);
	printf("\nSalary: %f",e[i].eSal);
	}

	return 0;
}

