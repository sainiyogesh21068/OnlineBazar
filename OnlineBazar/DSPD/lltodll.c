
#include<stdio.h>
#include<stdlib.h>
typedef struct node_tag{
	int data;
	struct node_tag *next;
	} node_type;
typedef enum{FAILURE,SUCCESS} status_code;

status_code InsertAtStart(node_type **list_ptr,int d)
{
	node_type *nptr;
	status_code sc=SUCCESS;
	nptr=(node_type*)malloc(sizeof(node_type));
	if(nptr!=NULL)
	{
		nptr->data=d;
		nptr->next=*list_ptr;
		*list_ptr=nptr;
	}
	else
	{
		sc=FAILURE;
	}
	return sc;
}

node_type* createlist(status_code *sc,int num)
{
	node_type *list_ptr, *nptr;
	int i,flag=1,data;
	list_ptr=NULL;
	printf("\nEnter Data");
	for(i=0; i<num && flag==1; i++)
	{
		scanf("%d",&data);
		*sc=InsertAtStart(&list_ptr,data);
	}
	return list_ptr;
}
void traversell(node_type *list_ptr)
{
	node_type *ptr;
	ptr=list_ptr;
	if(list_ptr==NULL)
	{
		printf("List Empty");
	}
	else
	{
		printf("\nlist Content\n");
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
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
dNode_type* insertAtEnd(dNode_type *lptr,int data)
{
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
void traversedll(dNode_type *lptr)
{
	dNode_type *nptr = lptr;
	printf("\ndoble link list Content\n");
	while(nptr != NULL)
	{
		printf("%d\t",nptr -> data);
		nptr = nptr -> next;
	}
	printf("\n");
}
dNode_type* createdll(node_type *ll)
{
	dNode_type *lptr = NULL;
	int data;
	node_type *ptr=ll,*temp;
	while(ptr!=NULL)
	{
		data=ptr->data;	
		lptr = insertAtEnd(lptr,data);
		temp=ptr;
		ptr=ptr->next;
		free(temp);
	}
	//lptr = reverse(lptr);
	return lptr;
}

void main()
{
	node_type *ll;
	int num;
	status_code sc;
	printf("\nEnter Number of Nodes:");
	scanf("%d",&num);
	ll=createlist(&sc,num);
	printf("\n");
	traversell(ll);
	printf("\n");
	dNode_type *dll;
	dll=createdll(ll);
	printf("\n");
	traversedll(dll);
}

