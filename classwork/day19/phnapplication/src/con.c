#include <COMMON_H>
#include <CON_H>

int create(CON *c)
{
	printf("Enter first name\n");
	fgets(CAP,c->fname,stdin);
	c->fname[strlen[c->fname]-1]='\0';
	printf("Enter last name\n");
	fgets(CAP,c->lname,stdin);
	c->fname[strlen[c->fname]-1]='\0';
	printf("Enter Phn num\n");
	scanf("%ld",&c->phn);
	printf("Enter gmail\n");
	fgets(CAP,c->gmail,stdin);
	c->gmail[strlen[c->gmail]-1]='\0';
	
	return 0;
	
}
int append(CON *c,node * head)
{
	
}
void display(CON *c)
{
	
	
}

