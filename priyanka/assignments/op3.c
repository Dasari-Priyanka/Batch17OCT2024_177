#include<stdio.h>
unsigned int reverseBytes(unsigned int num)
{
	unsigned int byte1,byte2,byte3,byte4;
	byte1=(num & 0xFF000000)>>24;
	byte2=(num & 0x00FF00000)>>8;
	byte3=(num & 0x0000FF00)<<8;
	byte4=(num & 0x000000FF)<<24;

	return(byte1|byte2|byte3|byte4);
}
unsigned int readInput()
{
	unsigned int num;
	printf("Enter a 32-bit unsigned integer: ");
	scanf("%x",&num);
	return num;
}
int main()
{
	unsigned int num = readInput();
	unsigned int reversedNum =reverseBytes(num);
	printf("Reversed bytes: 0x%X\n",reversedNum);
	return 0;
}
