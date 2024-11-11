#include <stdio.h>
#include <string.h>


struct Employee
{
	char eName[20];
	char eGender;
	char eAddress[20];
	int eId;
	float eSal;
}
typedef struct Employee EMP;
int main()
{
	int i,
	EMP e[5];
	char ch;
	printf("\nSelect the option: \n");
	switch(ch)
	{
		case 1: empDetails()
			break;
		case 2: Display()
			break;
		case 3: Search()
			break;
		case 4: update()
			break;
		default: 
			printf("\nEnter the correct colour code\n");
			break;

	}

	


}

void empDetails()
{

	printf("\nEmployee Details are: \n");
	for(i=0;i<5;i++)
	{
		printf("\nName: ");
		scanf("%s",&e[i].eName);
		printf("\nId: ");
		scanf("%d",&e[i].eId);
		printf("\nGender: ");
		scanf("%c",&e[i].eGender);
		printf("\nAddress: ");
		scanf("%s",&e[i].eAddress);
		printf("\nSalary: ");
		scanf("%f",&e[i].eSal);

	}
}
void Display()
{
	
	for(i=0; i<5;i++)
	{
		printf("\nName: %s",e[i].eName);
		printf("\nId: %d",e[i].eId);
		printf("\nName: %c",ie[i].eGender);
		printf("\nName: %s",e[i].eAddress);
		printf("\nName: %f",e[i].eSal);

	}
}
void search()
{
	printf("Enter the search option I,N,S:\n");
	switch(ch)
	{
	case 'I':
		sID();
		break;
	case 'N':
		sName();
		break;
	case 'S':
		sSal();
		break;
	default:
		printf("\nEnter the correct option");
}
int sId( int id)
{
	for(i=0;i<5;i++)
	{
		if(id==e[i].eID)
		{
			dis(i);
			break;
		}
	}
}
int dis( int i)
{
	printf("\nName: %s",e[i].eName);
	printf("\nId: %d",e[i].eId);
	printf("\nGender: %d",e[i].eGender);
	printf("\nAddress: %d",e[i].eAddress);
	printf("\nSalary: %d",e[i].eSal);
}
char sName(char name)
{
	for(i=0;i<5;i++)
	{
		if(strcmp(name,e[i].eName)==0)
		{
			dis(i);
			break;
		}
			
			
	}
}
int sSal(int sal)
{
	for(i=0;i<5;i++)
	{
		if(sal>6000 &sal<10000)
		{
			dis(i);
			break;
		}
	}
}


