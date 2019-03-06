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
dNode_type* insertAtEnd(dNode_type *lptr)
{
	printf("Enter data:");
	int data;
	scanf("%d",&data);	
	dNode_type *nptr = MakeNode(data);
	dNode_type *ptr = lptr;
	if(lptr == NULL)
		lptr = nptr;
	else
	{	
		ptr = lptr;
		while(ptr -> next != NULL)
		{
			ptr = ptr -> next;
		}
		nptr -> prev = ptr;
		ptr -> next = nptr;
	}
	return lptr;
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
		lptr = insertAtEnd(lptr);
	}
	//lptr = reverse(lptr);
	return lptr;
}

dNode_type* delete(dNode_type *ptr,dNode_type *head)
{
	dNode_type *ptr_prev,*temp;
	if(ptr->next==NULL && ptr->prev==NULL)
	{
		free(ptr);
		head=NULL;
	}
	else if(ptr->prev==NULL)
	{
		temp=ptr;
		head=ptr->next;
		head->prev=NULL;
		free(temp);
	}
	else if(ptr->next==NULL)
	{
		temp=ptr;
		ptr=ptr->prev;
		ptr->next=NULL;
		free(temp);
	}
	else
	{
		temp=ptr;
		ptr_prev=ptr->prev;
		ptr=ptr->next;
		ptr_prev->next=ptr;
		ptr->prev=ptr_prev;
		free(temp);
	}
	return head;
}

dNode_type* deletek(dNode_type* dll,int k)
{
	dNode_type *nptr = dll,*head=dll;
	printf("Deleted Nodes\n");
	while(nptr != NULL)
	{	
		if((nptr->data)%k==0)
		{
			printf("%d\n",nptr->data);
			head=delete(nptr,head);
		}
		nptr = nptr -> next;
	}
	return head;
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

void main()
{
	dNode_type *dll;
	dll=create();
	int k;
	printf("Enter k : ");
	scanf("%d",&k);
	printf("Before deletion \n");
	traverse(dll);
	dll=deletek(dll,k);
	printf("after deletion \n");
	traverse(dll);
}
		
