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


node_type* DeleteAtStart(node_type *list_ptr, int *dptr, status_code *sc)
{
	node_type *nptr;
	nptr=list_ptr;
	*sc=SUCCESS;
	if(list_ptr !=NULL)
	{
		list_ptr=list_ptr->next;
		*dptr=nptr->data;
		free(nptr);
	}
	else{
		*sc=FAILURE;
	}
	return list_ptr;
}

node_type* DeleteList(node_type *list_ptr,status_code *sc)
{
	node_type *nptr;
	int data;
	*sc=SUCCESS;
	if(list_ptr==NULL)
	{
		*sc=FAILURE;
	}
	printf("\nDeleted data\n");
	while(list_ptr !=NULL)
	{
		list_ptr=DeleteAtStart(list_ptr,&data,sc);
		printf("%d\n",data);
	}
	return (list_ptr);
}

node_type* DeleteAtEnd(node_type *list_ptr,int *dptr,status_code *sc)
{
	node_type *ptr,*prev;
	*sc=SUCCESS;
	if(list_ptr!=NULL)
	{
		if(list_ptr->next==NULL)
		{
			*dptr=list_ptr->data;
			free(list_ptr);
			list_ptr=NULL;
		}
		else
		{
			ptr=list_ptr;
			while(ptr->next!=NULL)
			{
				prev=ptr;
				ptr=ptr->next;
			}
			prev->next=NULL;
			*dptr=ptr->data;
			free(ptr);
		}
	}
	else
	{
		*sc=FAILURE;
	}
	return (list_ptr);
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

// void main()
// {
// 	int num,choice,flag=1;
// 	status_code sc;
// 	node_type *list_ptr;
// 	list_ptr=NULL;
// 	int data;
// 	while(flag!=0){
// 	printf("\t\t*****MENU****\n\t1.Create Whole List\n\t2.Delete Whole List\n\t3.Transverse\n\t4.InsertAtStart\n\t5.DeleteAtStart\n\t6.InsertAtEnd\n\t7.DeleteAtEnd\n\t8.Exit\n\tEnter Your Choice");
// 	scanf("%d", &choice);
// 	switch(choice)
// 	{
// 		case 1:
// 			{
// 				printf("\nEnter Number of Nodes:");
// 				scanf("%d",&num);
// 				list_ptr=createlist(&sc,num);
// 				break;
// 			}
// 		case 2:
// 			{
// 				list_ptr=DeleteList(list_ptr,&sc);
// 				break;
// 			}
// 		case 3:
// 			{
// 				traverse(list_ptr);break;
// 			}
// 		case 4:
// 			{
// 				printf("Enter Data");
// 				scanf("%d",&data);
// 				sc=InsertAtStart(&list_ptr,data);break;
// 			}
// 		case 5:
// 			{
// 				list_ptr=DeleteAtStart(list_ptr,&data,&sc);
// 				printf("\n Deleted Data : %d",data);break;
// 			}
// 		case 6:
// 			{
// 				printf("Enter Data");
// 				scanf("%d",&data);
// 				list_ptr=InsertAtEnd(list_ptr,data,&sc);break;
// 			}
// 		case 7:
// 			{
// 				list_ptr=DeleteAtEnd(list_ptr,&data,&sc);
// 				printf("\n Deleted Data : %d",data);break;
// 			}
// 		case 8:
// 			{
// 				flag=0;break;
// 			}
// 	}
// 	if(flag!=0){
// 	if(sc==SUCCESS)
// 	{
// 		printf("\n\n\t\tSUCCESS\t\t\n\n");
// 	}
// 	else
// 		printf("\n\n\t\tFailure\t\t\n\n");
// 	}
// 	}
// }
//
//
//
//
