#include<stdio.h>
int main()
{
	unsigned char num;
	printf("Enter an 8-bit unsigned integer(in hex,e.g 0xAA): ");
	scanf("%hhx",&num);
	unsigned char result=0;

	result|= (num&0x01)<<1;
	result|= (num&0x02)<<1;
	result|= (num&0x04)<<1;
	result|= (num&0x08)<<1;
	result|= (num&0x10)<<1;
	result|= (num&0x20)<<1;
	result|= (num&0x40)<<1;
	result|= (num&0x80)<<1;

	printf("The final number is: 0x%02X\n",result);

	return 0;

}
