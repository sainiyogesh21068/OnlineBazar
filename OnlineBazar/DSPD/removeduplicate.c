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

node *removeDulpicates(node *lptr)
{

	int sc=1,found=0;
 	node *nptr,*start=lptr;;
 	
  while(lptr->next!=NULL)
  {
		if(lptr->data==lptr->next->data)
		{
			nptr=lptr->next;
			lptr->next=nptr->next;
			free(nptr);
			nptr=NULL;
		}
		else
		{
	  	  lptr=lptr->next;
      }
   }
   return start;
}

void print(node *lptr)
{
	while(lptr!=NULL)
	{
		printf("%d ",lptr->data);
		lptr=lptr->next;
	}
	
}
 

int main()
{
	node *lptr=NULL;
	int size,i=0;
	lptr=create(lptr,&size);
	printf("list before remove\n");
	print(lptr);

	lptr=removeDulpicates(lptr);
	printf("list after remove\n");
   print(lptr);
}
