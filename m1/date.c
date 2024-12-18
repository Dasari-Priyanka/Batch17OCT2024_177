#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct DT
{
	int day;
	int month;
	int year;
};
void strtoken(char *[], struct DT *);
void compare(struct DT *, struct DT *);
int main()
{
	char datestr1[20];
	char datestr2[20];
	int i,N;
	struct DT date1,date2;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%s%s",datestr1,datestr2);
		strtoken(datestr1,&date1);
		strtoken(datestr2,&date2);
	
		compare(&date1,&date2);
	}
}
void strtoken(char *datestr[], struct DT *date)
{
	char *token;
	token=strtok(datestr,"/");
	date->day=atoi(token);
	token=strtok(NULL,"/");
	date->month=atoi(token);
	token=strtok(NULL,"/");
	date->year=atoi(token);
}
void compare(struct DT *date1, struct DT *date2)
{
	if(date1->year<date2->year)
	{
		printf("E\n");
	}
	else if(date1->year>date2->year)
	{
		printf("L\n");
	}
	else
	{
		if(date1->month<date2->month)
		{
			printf("E\n");
		}
		else if(date1->month>date2->month)
		{
			printf("L\n");
		}
		else
		{
			if(date1->day<date2->day)
			{
				printf("E\n");
			}
			else if(date1->day>date2->day)
			{
				printf("L\n");
			}
			else
			{
				printf("S\n");
			}

		}
	}

}
