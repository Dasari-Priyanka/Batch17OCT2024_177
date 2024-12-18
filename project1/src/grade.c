#include <COMMON_H>
#include <STD_H>
#define MAX=100
int findStudent(STD * std,int totalStd, int studentId)
{
	char feedback[100];
    for(int i=0;i<totalStd;i++)
    {
		if(std[i].id == studentId)
		{
        	feedBack(calGrade(std[i].score), feedback);
			break;
		}

	}
	return 0;
}

char calGrade(int score)
{
	char grade;
	if(score<=0)
	{
		return 1;
	}
	if(score>=90)
	{
		grade = 'A';
		break;
	}
	else if(score>=80)
	{
		grade ='B';
		break;
	}
	else if(score>=70)
	{
		grade = 'C';
		break;
	}
	else if(score>=60)
	{
		grade = 'D';
		break;
	}
	else
	{
		grade = 'F';
		break;
	}


	return grade;
}
char* feedBack(char grade, char* fb)
{
	char fb[MAX];
	if(grade == 'A')
	{
		strcpy(fb,"Excellent");
	}
	else if(grade == 'B')
	{
		strcpy(fb,"Good job");
		break;
	}
	else if(grade == 'C')
	{
		strcpy(fb,"Fair performance");
		break;
	}
	else 
	{
		strcpy(fb,"Failed");
		break;
	}
	return fb;
}




