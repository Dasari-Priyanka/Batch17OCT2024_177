#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc,char const *argv[])
{
	char op=argv[1][0];
	int op2=atoi(argv[2]);
	int op3=atoi(argv[3]);
	
	switch(op)
	{
		case '+':
			printf("\n%d + %d = %d\n",op2,op3,op2+op3);
			break;
		case '-':
			printf("\n%d - %d = %d\n",op2,op3,op2-op3);
			break;
		case '%':
			printf("\n%d %% %d = %d\n",op2,op3,op2%op3);
			break;
		case '*':
			printf("\n%d * %d = %d\n",op2,op3,op2*op3);
			break;
		case '/':
			printf("\n%d / %d = %d\n",op2,op3,op2/op3);
			break;
	}
	return 0;
	
}
