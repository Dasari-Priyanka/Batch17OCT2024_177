#include<stdio.h>
int main()
{
	char username[126];
	int age;
	float salary;
	short designationCode;
	char gender;

	printf("Enter username:\n");
	fgets(username,sizeof(username),stdin);

	printf("Enter age:");
	scanf("%d",&age);

	printf("Enter salary:");
	scanf("%f",&salary);


	printf("Enter designation code(1-6): ");
	scanf("%hd", &designationCode);

	printf("Enter gender(M/F): ");
	scanf(" ");
	scanf("%c",&gender);


	printf("\nUser Information:\n");
	printf("Username: %s",username);
	printf("Age:%d\n",age);
	printf("Salary: %.2f\n",salary);
	printf("Designation Code: %hd\n",designationCode);
	printf("Gender: %c\n",gender);

	return 0;
}
