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

node_type* InsertAtEnd(node_type* list_ptr, int d, status_code *sc)
{
	node_type *nptr,*ptr;
	*sc=SUCCESS;
	nptr=(node_type*)malloc(sizeof(node_type*));
	if(nptr==NULL)
	{
		*sc=FAILURE;
	}
	nptr->data=d;
	nptr->next=NULL;
	if(list_ptr==NULL)
	{
		list_ptr=nptr;
	}
	else
	{
		ptr=list_ptr;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=nptr;
	}
	return list_ptr;
}

void traverse(node_type *list_ptr)
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
			printf("\n%d",ptr->data);
			ptr=ptr->next;
		}
	}
}

void main()
{
	node_type *list_ptr;
	int prod,num;
	int count=0;
	status_code sc;
	printf("\nEnter Number of Nodes:");
	scanf("%d",&num);
	list_ptr=createlist(&sc,num);
	traverse(list_ptr);
	printf("\nEnter Number : ");
	scanf("%d",&prod);
	node_type *s_ptr,*f_ptr;
	s_ptr=list_ptr;
	f_ptr=s_ptr->next;
	while(s_ptr!=NULL && s_ptr->next!=NULL)
	{
		if(f_ptr!=NULL && (s_ptr->data * f_ptr->data) == prod )
		{
			count++;
			f_ptr=f_ptr->next;
		}
		else if((s_ptr->data * f_ptr->data) > prod || f_ptr==NULL)
		{
			s_ptr=s_ptr->next;
			if(s_ptr!=NULL)
			{
				f_ptr=s_ptr->next;
			}
		}
		else
		{
			f_ptr=f_ptr->next;
		}
	}
	printf("\n%d\n",count);
}
	

			

