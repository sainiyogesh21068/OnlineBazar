#include<stdio.h>
#include<stdlib.h>

typedef struct node_tag
{
	int data;
	struct node_tag *next;
}node;


node *create(node *lptr)
{
	
	node *nptr;
	int i;
	for(i=6;i>0;i--)
	{
		nptr=malloc(sizeof(node));
		nptr->data=i*10;
		nptr->next=lptr;
		lptr=nptr;
	}
	return lptr;
}

int main()// 10 20 30 40 50 60
{
	node *lptr ,*nptr,*head,*start;
	lptr=NULL;
	int i;
	
	lptr=create(lptr);
	start=lptr;
	printf("before rotate\n");
	while(lptr!=NULL)
	{
		printf("%d ",lptr->data);
		lptr=lptr->next;
	}
	lptr=start;
	for(i=1;i<4;i++)
	{
		lptr=lptr->next;
	}
	
	head=lptr->next;
	lptr->next=NULL;
	lptr=head;

	while(head->next!=NULL)
	{
		head=head->next;
	}
	head->next=start;
		printf("after rotation\n");
	while(lptr!=NULL)
	{
		printf("%d ",lptr->data);
		lptr=lptr->next;
	}
	
}
