#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int val;
	struct node *ptr; 
}NODE;
void printList(NODE *);
void appendNode(NODE *, NODE *);
int main()
{
	NODE  n1,n2,n3,n4,n5;
	NODE *head;
	n1.val=10;
	n2.val=20;
	n3.val=30;
	n4.val=40;
	n5.val=50;
	n5.ptr=NULL;
	n1.ptr=NULL;
	n2.ptr=NULL;
	n3.ptr=NULL;
	n4.ptr=NULL;
	n1.ptr=&n2;
	n2.ptr=&n3;
	n3.ptr=&n4;
	n4.ptr=&n5;
	head=&n1;
	printList(head);
	head=&n1;
	
	appendNode(head,&n2);
	

	return 0;
}
void printList(NODE *head)
{
	
	while(head!=NULL)
	{
		printf("%d->",head->val);
		head=head->ptr;
	}
	printf("NULL\n");
}
void appendNode(NODE *head, NODE *nn)
{
	printf("\nIn append mode:\n");
	while(head->ptr!=NULL)
	{
		printf("%d->",head->val);
		head=head->ptr;
	}
	printf("\n%d",head->val);
	printf("\n%p",head->ptr);
	head->ptr=nn;

}

