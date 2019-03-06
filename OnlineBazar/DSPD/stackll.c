#include<stdio.h>
#include<stdlib.h>

typedef struct node_tag
{
	int data;
	struct node_tag *next;
}node;

typedef struct stack
{
	node *top;
	
}stck;

stck *Push(stck *stk)
{
	node *nptr;
	int d;
	int sc=1;
	
	nptr=malloc (sizeof(node));
	if(nptr==NULL)
	{
	 sc=0;

	}
	else
	{
		printf("enter data\n");
		scanf("%d",&d);
		nptr->data=d;
		nptr->next=stk->top;
		stk->top=nptr;
	
	}
	if(sc==1)
	{
		printf("%d add successfully\n",d);
	}
	else
	printf("error: data not added\n");

return stk;

}
stck *Pop(stck *stk,int *d)
{
	  node *nptr;
	int sc=1;
	if(stk->top->next==NULL)
	{
	 sc=0;

	}
	else
	{
		 nptr=stk->top;
 		 *d=nptr->data;
		 stk->top->next=nptr->next;
		 free(nptr);
	}
	if(sc==1)
	{
		printf("%d delete successfully\n",*d);
	}
	else
	printf("error: no data found\n");

return stk;

}


int main()
{
 	 int choise,d,ans;
 	 stck stk;
 	 
 	// intialize(&stk);
	 stk.top=NULL;
	 do{

	 printf("enter your choise\n 1. for Push \n2. for Pop\n");
	 scanf("%d",&choise);
	 switch(choise)
	 {
	 	case 1:
	 		{
			  Push(&stk);
			  break;
	 		}
 		case 2:
			{
			 Pop(&stk,&d);
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
