#include <stdio.h>
#include <string.h>
int main()
{
	char id[20],salary[20],phno[20];
	char name[20],gender[2],address[20],desg[10];
	char buff[1024] = {'\0',};
	fgets(id,19,stdin);
	fgets(name,19,stdin);
	fgets(gender,19,stdin);
	fgets(address,19,stdin);
	fgets(salary,19,stdin);
	fgets(desg,19,stdin);
	puts("| id | name | gender | address | phno | salary | desg |\n");
	strcat(buff,"| ");

	strcat(buff,id);
	strcat(buff," |");
	strcat(buff,name);
	strcat(buff," |");
	strcat(buff,gender);
	strcat(buff," |");
	strcat(buff,address);
	strcat(buff," |");
	strcat(buff,phno);
	strcat(buff," |");
	strcat(buff,salary);
	strcat(buff," |");
	strcat(buff,desg);
	strcat(buff," |");
	printf("%s",buff);
	return 0;
}

