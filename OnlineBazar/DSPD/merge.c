#include<stdio.h>
#include<stdlib.h>

typedef struct node_tag{
	int data;
	struct node_tag *next;
	} node_type;
typedef enum{FAILURE,SUCCESS} status_code;

/*status_code InsertAtStart(node_type **list_ptr,int d)
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
}*/
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

node_type* createlist(status_code *sc,int num)
{
	node_type *list_ptr, *nptr;
	int i,flag=1,data;
	list_ptr=NULL;
	printf("\nEnter Data");
	for(i=0; i<num && flag==1; i++)
	{
		scanf("%d",&data);
		list_ptr=InsertAtEnd(list_ptr,data,sc);
	}
	return list_ptr;
}

node_type* Merge(node_type *list1, node_type *list2)
{
	node_type *head, *tail, *ptr1, *ptr2;
	if(list1==NULL)
	{
		head=list2;
	}
	else if(list2==NULL)
	{
		head=list1;
	}
	else
	{
		head=list1;
		ptr1=head->next;
		ptr2=list2;
		tail=head;
		int count=2;
		while(ptr1!=NULL && ptr2!=NULL)
		{
			if(count%2==0)
			{
				tail->next=ptr2;
				tail=ptr2;
				ptr2=ptr2->next;
			}
			else
			{
				tail->next=ptr1;
				tail=ptr1;
				ptr1=ptr1->next;
			}
			count++;
		}
		if(ptr1!=NULL)
		{
			tail->next=ptr1;
		}
		else
		{
			tail->next=ptr2;
		}
	}
	return head;
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
	status_code sc;
	node_type *list_ptr1,*list_ptr2;	
	int num1,num2;
	printf("\nEnter Number of Nodes in list 1:");
	scanf("%d",&num1);
	list_ptr1=createlist(&sc,num1);
	printf("\nEnter Number of Nodes in list 2:");
	scanf("%d",&num2);
	list_ptr2=createlist(&sc,num2);
	printf("entered Lists are\n");
	traverse(list_ptr1);
	printf("\n");
	traverse(list_ptr2);
	list_ptr1=Merge(list_ptr1,list_ptr2);
	printf("\nAfter Merge\n");
	traverse(list_ptr1);
}




