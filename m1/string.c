#include<stdio.h>
#include<string.h>
int check_a(char *,int );
int check_is(char *,int);
int main()
{
	char N,str[50];
	int i,sum,n1,n2,len;
	scanf("%d",&N);
	getchar();
	for(i=0;i<N;i++)
	{
		n1=0,n2=0;
		scanf("%[^\n]s",str);
		getchar();
		len=strlen(str);
		n1=check_is(str,len);
		n2=check_a(str,len);
		sum=n1+n2;
		printf("%d\n",sum);
	}



}
int check_is(char *a,int len)
{
	int i,index1;
	for(i=0;i<len;i++)
	{
		if((a[i]=='i')&&(a[i+1]=='s'))
		{
			i--;
			index1=i;
			break;
		
		}
	}
	printf("%d\n",index1);
	if(index1!=0)
		return index1;
	else
		return -1;
}
int check_a(char *a,int len)
{
	int i,index2;
	for(i=0;i<len;i++)
	{
		if(a[i]=='a')
		{
			index2=i;
			break;
		}
	}
	printf("%d\n",index2);
	if(index2!=0)
		return index2;
	else
		return -1;
}

