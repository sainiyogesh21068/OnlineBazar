#include<stdio.h>
#include<stdlib.h>
typedef enum{FAILURE,SUCCESS} status_code;
typedef enum{FALSE,TRUE} boolean;
typedef struct d_Node
{
	int data;
	struct d_Node *next;
	struct d_node *prev;
} dNode_type;
dNode_type* MakeNode(int data)
{
	dNode_type *nptr;
	nptr = (dNode_type*)malloc(sizeof(dNode_type));
	nptr -> data = data;
	nptr -> next = NULL;
	nptr -> prev = NULL;
}
dNode_type* insertAtStart(dNode_type *lptr)
{
	printf("Insert data:");
	int data;
	scanf("%d",&data);
	dNode_type *nptr = MakeNode(data);
	nptr -> next = lptr;
	lptr = nptr;
	lptr -> prev = NULL;
	return lptr;
}
dNode_type* create()
{
	dNode_type *lptr = NULL;
	printf("Enter number of nodes:");
	int nodes,i;
	scanf("%d",&nodes);
	for(i=0;i<nodes;i++)
	{
		lptr = insertAtStart(lptr);
	}
	return lptr;
}
dNode_type* reverse(dNode_type *lptr)
{
	dNode_type *head = lptr,*middle = NULL,*tail;
	while(head != NULL)
	{
		tail = middle;
		middle = head;
		head = head -> next;
		middle -> next = tail;
		middle -> prev = head;
	}
	return middle;
}
void traverse(dNode_type *lptr)
{
	dNode_type *nptr = lptr;
	while(nptr != NULL)
	{
		printf("%d\t",nptr -> data);
		nptr = nptr -> next;
	}
	printf("\n");
}

int main()
{
	dNode_type *dll;
	dll=create();
	int k;
	printf("Before reverse \n");
	traverse(dll);
	dll=reverse(dll);
	printf("after reverse \n");
	traverse(dll);
	return 0;
}
