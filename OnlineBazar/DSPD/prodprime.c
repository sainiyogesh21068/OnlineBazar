#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef enum{FALSE,TRUE} boolean;
typedef enum{FAILURE,SUCCESS} status_code;
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
void traversell(dNode_type *lptr)
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
void productll(dNode_type *lptr)
{
	int product=1,i;
	int count=0;
	int n;
	int flag=0;
	dNode_type *nptr = lptr;
	printf("\ndoble link list Content\n");
	while(nptr != NULL)
	{
		flag=0;
		n=nptr->data;
		for(i = 2; i <= n/2; ++i)
    		{
        		// condition for nonprime number
        		if(n%i == 0)
        		{
            			flag = 1;
            			break;
        		}
    		}

    		if (n != 1) 
    		{
    			if (flag == 0)
				product=(product)*(n);
    		}		
		nptr = nptr -> next;
	}
	printf("product = %d",product);
}
void main()
{
	dNode_type *dll;
	dll=create();
	printf("\n");
	traversell(dll);
	printf("\n");
	productll(dll);
}
