#include <common.h>
#include <emp.h>

int main()
{
	FILE *fp;
	EMP *e=NULL;
	EMP *temp = NULL;
	EMP *head = NULL;
	char line[BUFF];
	NODE *nn=NULL;
	NODE *head=NULL,*temp=NULL;
	int flag=0;
	int key=0;
	int i;

	system("clear");

	fp = fopen("./data/db.txt","r");

	if(fp == NULL)
	{
		perror("fopen: ");
		return 1;
	}
	// e = (EMP *)malloc(5*sizeof(EMP));
	// temp = e;

	memset(line,'\0',BUFF);

	while(fgets(line,BUFF,fp)!=NULL)
	{
		line[strlen(line)-1] = '\0';
		e = (EMP *)malloc(sizeof(EMP));
		
		getDetails(e,line);
		e->next = NULL;
		head = appendNode(head, e);
		
	}


	while(1)
	{
		switch(dispMainMenu())
		{
			case 1:
					nn = createNode(nn);
					head = addNodeBeg(head,nn);
					break;
			case 2:
					nn = createNode(nn);
					head = appendNode(head,nn);
					break;
			case 3:
					printf("\nEnter the key of the node: ");
					scanf("%d",&key);
					delNode(head,key);
					break;
			case 4:
					printListFD(head);
					break;
			case 5:
					printListBD(head);
					break;
			case 6:
					flag = 1;
					break;
			default:
					printf("\nEnter the correct Choice");
					break;
		}
		if(flag == 1)
			break;
	}

	printf("\n\n");


	printList(head);
	
	printf("\n\n");
	return 0;
}
