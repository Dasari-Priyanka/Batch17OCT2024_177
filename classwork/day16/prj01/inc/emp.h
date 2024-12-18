#ifndef EMP_H
#define EMP_H

typedef struct Employee
{
	int id;
	int phno;
	int sal;
	char Name[50];
	char g;
	struct Employee *next;
}EMP;
typedef struct Stack
{
	int val;
	char arr[50];
}
EMP push(int *val);
EMP pop();
void disStack();

#endif
