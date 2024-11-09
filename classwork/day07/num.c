#include <stdio.h>
int main()
{
	int n1,n2,n3,n4,n5;
	scanf("%d %d %d %d %d",&n1,&n2,&n3,&n4,&n5);
	if(n1>n2)
	{ 
		if(n1>n3)
		{
			if(n1>n4)
			{
				if(n1>n5)
				{
					printf("n1 is greatest");
				}
				else
				{
					printf("n5 is greatest");
				}
			}
			else
			{
				if(n4>n5)
				{
					printf("n4 is greatest");
				}
				else
				{
					printf("n5 is greatest");
				}
			}
		}
		else
		{
			if(n3>n4)
			{
				if(n3>n5)
				{
					printf("n3 is greatest");
				}
				else
				{
					printf("n5 is greatest");
				}
			}
			else
			{
				if(n4>n5)
				{
					printf("n4 is greatest");
				}
				else
				{
					printf("n5 is greatest");
				}
			}
		}
	}
	else
	{
    	if(n2>n3)
		{
			if(n2>n4)
			{
				if(n2>n5)
				{
					printf("n2 is greatest");
				}
				else
				{
					printf("n5 is greatest");
				}
			}
			else
			{
				if(n4>n5)
				{
					printf("n4 is greatest");
				}
				else
				{
					printf("n5 is greatest");
				}
			}
		}
		else
		{
		if(n3>n4)
		{
			if(n3>n5)
			{
				printf("n3 is greatest");
			}
			else
			{
				printf("n5 is greatest");
			}
		}
		else
		{
			if(n4>n5)
			{
				printf("n4 is greatest");
			}	
			else
			{
				printf("n5 is greatest");
			}
		}
		}
	}    
    return 0;
}
