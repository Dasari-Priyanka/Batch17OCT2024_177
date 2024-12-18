#include <stdio.h>
#include <string.h>
typedef enum
{
    Software_Fresher,
    Software_Engineer,
    Senior_Software_Engineer,
    Team_Lead,
    Senior_Team_Lead

}design;
typedef struct Employee
{
    char name[50];
    unsigned int age;
    design designation;
}EMP;

void read(EMP *);
void display(EMP );
int update(EMP *);
EMP copy(EMP);
int main()
{
    EMP e[3];
    read(&e[0]);
    read(&e[1]);
    read(&e[2]);
    display(e[0]);
    display(e[1]);
    display(e[2]);
    return 0;
}
void read(EMP *e)
{
    int ch;
    printf("\nEnter name: ");
    fgets(e->name,50,stdin);
    e->name[strlen(e->name)-1]='\0';
    printf("\nEnter age: ");
    scanf("%u",&e->age);
    printf("\nEnter designation: ");
    printf("\n0.Software Fresher");
    printf("\n1.Software Engineer");
    printf("\n2.Senior Software Engineer");
    printf("\n3.Team Lead");
    printf("\n4.Senior Team Lead");
    scanf("%d",&ch);
    getchar();
    e->designation=ch;
}
void display(EMP e)
{
    printf("\nEmployee details\n");
    printf("\nName: %s",e.name);
    printf("\nAge: %u",e.age);
    printf("\nDesignation: ");
    switch(e.designation)
    {
        case Software_Fresher: printf("Software Fresher\n");break;
        case Software_Engineer: printf("Software Engineer\n");break;
        case Senior_Software_Engineer: printf("Senior Software Engineer\n");break;
        case Team_Lead: printf("Team Lead\n");break;
        case Senior_Team_Lead: printf("Senior Team Lead\n");break;
        default: printf("not valid\n");break;
    }
}
int update(EMP *e)
{
    int ch;
    getchar();
    printf("\nEnter new name: ");
    fgets(e->name,50,stdin);
    e->name[strlen(e->name)-1]='\0';
    printf("\nEnter new age: ");
    scanf("%u",&e->age);
    printf("\nEnter new designation: ");
    printf("\n0.Software Fresher");
    printf("\n1.Software Engineer");
    printf("\n2.Senior Software Engineer");
    printf("\n3.Team Lead");
    printf("\n4.Senior Team Lead");
    scanf("%d",&ch);
    e->designation=ch;

}
EMP copy(EMP e)
{
    EMP ne;
    strcpy(ne.name,e.name);
    ne.age=e.age;
    ne.designation=e.designation;
    return ne;
}

