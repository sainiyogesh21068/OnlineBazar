#include<stdio.h>
#include<stdlib.h>

typedef struct node_tag
{
	int data;
	struct node_tag *next;
}node;

node *Push(node *stk,int d)
{
	node *nptr;
	int sc=1;
	nptr=malloc (sizeof(node));
	if(nptr==NULL)
	{
	 sc=0;

	}
	else
	{
		nptr->data=d;
		nptr->next=stk;
		stk=nptr;
	}

return stk;

}

node *Pop(node *stk,int *d)
{
	  node *nptr;
	int sc=1;
	if(stk==NULL)
	{
	 sc=0;

	}
	else
	{
		 nptr=stk;
 		 *d=nptr->data;
		 stk=stk->next;
		 free(nptr);
		 nptr=NULL;
	}
return stk;

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
 	 int choise,d,ans;
 	 node *stk,*stk2;

 	// intialize(&stk);
	 stk=NULL;
	 stk2=NULL;
	 do{

	 printf("\nenter your choise\n 1. for Push in queue \n2. for Pop from queue\n");
	 scanf("%d",&choise);
	 switch(choise)
	 {
	 	case 1:
	 		{
		 	printf("enter data\n");
			scanf("%d",&d);
			  stk=Push(stk,d);
			  print(stk);
			  break;
	 		}
		 	case 2:
			{
			 stk2=Pop(stk2,&d);
			 printf("%d  ",d);
			 break;
		 	}
		 	case 3:
			 {
			 stk=Pop(stk,&d);
			  //print(stk);
			  stk2=Push(stk2,d);
			  break;
		}
	   default:
	 	{
	 		printf("you enter wrong key\n");

 		}
 	}
 	printf("do you want go back\n");
 	scanf("%d",&ans);
 }while(ans==1);

}
