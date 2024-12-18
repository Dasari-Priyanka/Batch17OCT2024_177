#include<stdio.h>
int main()
{
	int test1_score,test2_score,test3_score,project_score,eligibility;
	printf("Enter the test1,test2,test3,project scores:\n");
	scanf("%d%d%d%d",&test1_score,&test2_score,&test3_score,&project_score);
	if(test1_score>=75)
	{
		if(test2_score>=75)
		{
			if(test3_score>=70)
			{
				if(project_score>=75)
					eligibility=1;
			}
		}
	}
	else
		eligibility=0;

	switch(eligibility)
	{
		case 1: 
			printf("Eligible for deployment\n");
			break;
		case 2:
			printf("Not Eligible for deployment\n");
			break;
		case 3:
			printf("Error in eligibility check\n");
			break;

	}
}
