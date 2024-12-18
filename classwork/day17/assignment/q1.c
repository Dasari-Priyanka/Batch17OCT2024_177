/*
1.Create an empty string, D.
2. Let N be the size of the received string M.
3. Place the first ceil(N/2) characters from M at the odd positions in string D.
4. Take the remaining characters from M and put them at the even positions in D.
5. D is the output string.

I/p
aebfcgdh

o/p
abcdefgh
*/
#include<stdio.h>
#include<string.h>
void  changeChar(char *,char *);
int main()
{
	char M[]="aebfcgdh";
	int N;
	//scanf("%s",M);
	N=strlen(M);
	char D[N+1];
	changeChar(D,M);

	printf("%s\n",D);
	
	return 0;
}


void changeChar(char *D,char *M)
{
	int i,N,half,odd;
	N=strlen(M);
	printf("%d\n",N);
	half=N/2;
	odd=0;
	for(i=0;i<N;i++)
	{
		if((i+1)%2!=0)
		{
			D[odd]=M[i];
			odd++;
			printf("%c\n",D[odd]);
		}
	
		else
		{
			D[half]=M[i];
			half++;
			printf("%c\n",D[half]);
		}
	}
	D[N]='\0';	
}

