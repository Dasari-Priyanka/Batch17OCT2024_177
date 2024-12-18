#include<stdio.h>
unsigned int readInput();
int countOnes(unsigned char num);
void generateParityBits(unsigned int num);

int main()
{
	unsigned char num = readInput();
	generateParityBits(num);

	return 0;
}
unsigned int readInput()
{
	unsigned int num;
	printf("Enter a 32-bit unsigned integer:\n");
	scanf("%x",&num);
	return num;
}
int countOnes(unsigned char num)
{
	int count=0;
	while(num)
	{
		count+=num&1;
		num>>=1;

	}
	return count;
}
void generateParityBits(unsigned int num)
{
	int count=countOnes(num);
	int evenParity =(count%2==0)?0:1;
	int oddParity =(evenParity==0)?1:0;

	printf("The even parity bit is:%d\n",evenParity);
	printf("The odd parity bit is:%d\n",oddParity);
}
