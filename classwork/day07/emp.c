#include <stdio.h>
int main()
{
	int id,salary,slno;
	long int phno;
	char name[10],address[10],desg[5];
	char gender;
    printf("Enter slno: \n");
	scanf("%d", &slno);
	printf("\nEnter the employee id:\n ");
	scanf("%d", &id);
	printf("\nEnter the employee name: \n");
	scanf("%s", name);
	printf("\nEnter the employee gender F or M: \n");
	scanf(" ");
	scanf("%c", &gender);
	printf("\nEnter the employee address: \n");
	scanf("%s", address);


	printf("\nEnter the employee phone number: \n");

	scanf("%ld", &phno);
	printf("\nEnter the employee salary: \n");
	scanf("%d", &salary);
	printf("\nEnter the employee designation: \n");
	scanf("%s", desg);
	

	printf("\n| Slno | Id | Name | GENDER | ADDRESS | PHNO | SALARY | DESG|\n");
	printf("|%d | %3d | %s | %c | %s | %ld | %d | %s\n |",slno,id,name,gender,address,phno,salary,desg);

	return 0;
}

