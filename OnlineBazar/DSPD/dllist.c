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
dNode_type* deleteAtStart(dNode_type *lptr,int *dptr)
{	
	dNode_type *nptr,*ptr;
	if(lptr == NULL)
		printf("Link is empty\n");
	else
	{
		ptr = lptr;
		if(ptr -> next == NULL)	
		{
			*dptr = ptr -> data;
			lptr -> next = lptr -> prev = NULL;
			lptr = NULL;
			free(ptr);
		}
		else
		{
			*dptr = ptr -> data;	
			lptr = lptr -> next;
			lptr -> prev = NULL;
			free(ptr);
			ptr = NULL;
		}
	}
	return lptr;
}
dNode_type* deleteAtEnd(dNode_type *lptr,int *dptr)
{
	dNode_type *nptr,*ptr;
	if(lptr == NULL)
		printf("Link is empty\n");
	else
	{
		ptr = lptr;
		if(ptr -> next == NULL)	
		{
			*dptr = ptr -> data;
			lptr -> next = lptr -> prev = NULL;
			lptr = NULL;
			free(ptr);
		}
		else
		{
			while(ptr -> next != NULL)
			{
				ptr = ptr -> next;
			}
			nptr = ptr -> prev;
			*dptr = ptr -> data;
			nptr -> next = NULL;
			free(ptr);
			ptr = NULL;
		}
	}
	return lptr;
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
	lptr = reverse(lptr);
	return lptr;
}
//8
dNode_type* Merge(dNode_type *lptr1,dNode_type *lptr2)
{
	dNode_type *ptr2,*ptr1,*nptr;
	ptr1 = lptr1;
	ptr2 = lptr2;
	while(ptr2 != NULL && ptr1 -> next != NULL)
	{
		nptr = (dNode_type*)malloc(sizeof(dNode_type));
		nptr -> data = ptr2 -> data;
		nptr -> next = ptr1 -> next;
		nptr -> prev = ptr1;
		ptr1 -> next = nptr;
		ptr1 = ptr1 -> next -> next;
		ptr2 = ptr2 -> next;
	}
	if(ptr1 -> next == NULL)
		ptr1 -> next = ptr2;
	return lptr1;
}
//9.
dNode_type* deleteNodesDivisibleByK(dNode_type *lptr,int k)
{
	dNode_type *nptr,*ptr,*next;
	while(lptr -> next != NULL && lptr -> data % k == 0)
	{
		ptr = lptr;
		lptr = lptr -> next;
		free(ptr);
	}
	if(lptr -> next == NULL)
	{
		if(lptr -> data % k == 0)
			lptr = NULL;
	}
	else
	{
		ptr = nptr = lptr;
		while(nptr -> next != NULL)
		{
			if(nptr -> data % k != 0)
			{
				ptr = nptr;
				nptr = nptr -> next;
			}
			if(nptr -> data % k == 0)
			{
				if(nptr -> next == NULL)
				{
					ptr -> next = NULL;
					free(nptr);
					nptr = NULL;
				}
				else
				{
					//dNode_type *node = nptr;
					next = nptr -> next;
					next -> prev = ptr;
					ptr -> next = next;
					//free(node);
					//node = NULL;
					/*if(nptr -> data % k == 0)
					{
						node = nptr;
						next = nptr -> next;
						next -> prev = ptr;
						ptr -> next = next;
						free(node);
						node = NULL;
					}*/
				}
			}
		}
	}
	return lptr;
}
int main()
{
		int x = 1;
		dNode_type *lptr = NULL,*lptr1,*lptr2;
		while(x<=9)
		{
			printf("Select from the following:\n");
			printf("1.Insert at start\n");
			printf("2.Insert at end\n");
			printf("3.Delete at start\n");
			printf("4.Delete at end\n");
			printf("5.Traverse\n");
			printf("6.Create list\n");
			printf("7.Reverse list\n");
			printf("8.Merge two lists alternately\n");
			printf("9.deletes nodes with numbers divisible by k\n");
			scanf("%d",&x);
			switch(x)
			{
				case 1:
				{
					lptr = insertAtStart(lptr);
					break;
				}
				case 2:
				{
					lptr = insertAtEnd(lptr);
					printf("Data added");
					break;
				}	
				case 3:
				{
					int d;
					lptr =  deleteAtStart(lptr,&d);
					printf("%d deleted successfully\n",d);
					break;
				}
				case 4:
				{
					int d;
					lptr =  deleteAtEnd(lptr,&d);
					printf("%d deleted successfully\n",d);
					break;
				}
				case 5:
				{
					traverse(lptr);
					break;
				}
				case 6:
				{
					lptr = create();
					break;
				}
				case 7:
				{
					lptr =  reverse(lptr);
					break;
				}
				case 8:
				{
					printf("Enter first list:\n");
					lptr1 = create();
					traverse(lptr1);		
					printf("\nEnter second list:\n");
					lptr2 = create();
					traverse(lptr2);
					printf("\n");
					lptr = Merge(lptr1,lptr2);
					traverse(lptr);
					break;
				}
				case 9:
				{
					printf("This function deletes nodes with numbers divisible by k\n");
					printf("Enter k:");
					int k;
					scanf("%d",&k);
					lptr = deleteNodesDivisibleByK(lptr,k);
					break;
				}
			}
		}
		return 0;
}
