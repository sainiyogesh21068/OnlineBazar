#include<stdio.h>
#include<stdlib.h>

typedef struct node_tag
{
	char data;
	struct node_tag *next;
}node;

typedef struct stack
{
	node *top;

}stck;

stck *Push(stck *stk,char d)
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
		nptr->next=stk->top;
		stk->top=nptr;
	}
return stk;
}
stck *Pop(stck *stk,char *d)
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
return stk;
}


int main()
{
	 char d;
	 char ch;
	 int i=0;
	char str[50];
 	 stck stk,stk2;
	scanf("%s",str);
 	// intialize(&stk);
	 stk.top=NULL;
	 do{
	  	Push(&stk,str[i]);
		 i++;
	 }while(str[i]!='\0');
	 stk2=stk;
	 while(stk2.top!=NULL)
	 {
		stk2.top=stk2.top->next;
		}
	 int found=1,count=0;
	 while(count<=i/2)
	 {
		Pop(&stk,&d);
		 if(stk2.top->data!=d)
		 {
		 	found==0;
		 }
		 stk2.top=stk2.top->next;
		 count++;
	 }
if(found==1)
{
	printf("string in palindrom");
}
else
printf("not in palindrom\n");

}
