//10 20 30 40 50 60
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

node *reverselist(node *lptr)
{
	node *head;
	head=lptr;
	if(lptr->next!=NULL)
	{
	while(lptr->next->next!=NULL)
	{
	 lptr=lptr->next;
	}
	lptr->next->next=head;
	head=lptr->next;
	lptr->next=NULL;

  head->next=reverselist(head->next);
}
  return head;
}


int main()// 45 7 6 8 9 5
{
	node *lptr ,*start;
	lptr=NULL;
	int i;
	lptr=create(lptr);
	start=lptr;
	printf("before rotate\n");
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->next;
	}
	lptr=reverselist(lptr);
   start=lptr;
	printf("\nafter reverse\n");
   while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->next;
	}
}
