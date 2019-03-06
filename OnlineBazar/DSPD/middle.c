#include<stdio.h>
#include<stdlib.h>

typedef struct node_tag
{
	int data;
	struct node_tag *next;
	
}node;

node * Add(node *lptr,int d,int *sc)
{
	node *nptr;
   *sc=1;
	nptr=malloc (sizeof(node));
	if(nptr==NULL)
	{
	  sc=0;
	}
	else
	{
		nptr->data=d;
		nptr->next=lptr;
		lptr=nptr;
	}
return lptr;
}

node *create(node *lptr,int *size)
{
	int ans,d,sc,count=0;
	printf("do you want add a data\n");
	scanf("%d",&ans);
	while(ans==1)
	{
		count++;
		printf("enter data\n");
		scanf("%d",&d);
		lptr=Add(lptr,d,&sc);
		if(sc==1)
		{
			printf("data add successfully\n");
		}
		else
			printf("error\n");

		printf("do you want add another node\n");
		scanf("%d",&ans);
	}
	*size=count;
	
	return lptr;
}

int main()
{
	node *lptr=NULL;
	int size,i=0;
	lptr=create(lptr,&size);
	if(size==0)
	{
		printf("no element in list\n");
	}
	else if(size==1)
	{
		printf("%d",lptr->data);
	}
	else{
		 while(i<(size/2)-1)
		 {
		 	lptr=lptr->next;
		 	i++;
   	 }
			if(size%2==0)
			{
				printf("middle element are: %d  %d",lptr->data,lptr->next->data);
			}
			else
		 		 printf("%d",lptr->next->data);
		
	}
}
