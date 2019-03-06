#include<stdio.h>
#include<stdlib.h>
typedef struct node_tag
{
	int data;
	struct node_tag *next;
}node;

node  *Add(node *lptr,int d)
{
	node *nptr;
	nptr=malloc(sizeof(node));
	if(nptr!=NULL)
	{
		nptr->data=d;
		nptr->next=lptr;
		lptr=nptr;
	}
return lptr;
}

node *create(node *lptr,int num)
{
   int d=num;
	while(d!=0)
	{
		lptr=Add(lptr,d%10);
		d=d/10;
	}
	return lptr;
}
node *reverselist(node *lptr)
{
	node *head;
	head=lptr;
	if(lptr->next!=NULL)
	{
	while(lptr->next->next!=NULL)
	{
	 lptr=lptr->next;
	}
	lptr->next->next=head;
	head=lptr->next;
	lptr->next=NULL;

    head->next=reverselist(head->next);
  }
  return head;
}


node *addnumber(node *lptr1, node *lptr2)
{
	node *nptr,*head;
	int sum;
	printf("ygjh");
	/*while(lptr1!=NULL)
	{
		sum=lptr1->data+lptr2->data;
		lptr2->data=sum%10;
		lptr2=lptr2->next;// 321
		lptr1=lptr1->next;//432
		lptr2->data+=(sum/10);
	}
	//lptr2=head;
    while(lptr2!=NULL)
   {
   	printf("%d",lptr2->data);
   	lptr2=lptr2->next;
	}



			/*while(lptr2!=NULL)
			{

					lptr2->data+=sum/10;
					
					lptr2=lptr2->next;
					lptr2->data+=1;
					if(lptr2->data>10)
					{
						sum=lptr2->data;
						lptr2->data=sum%10;
						nptr=malloc(sizeof(node));
						nptr->data=sum/10;
						nptr->next=NULL;
						lptr2->next=nptr;
						lptr2=lptr2->next;
				   }
		}
		else
		{
		 lptr2->data=sum;
		 lptr2=lptr2->next;
		 lptr1=lptr1->next;
	   }
	}*/
	return head;
}

int main()
{
	node *lptr1=NULL,*lptr2=NULL;
	int num1,num2;
	printf("enter first number \n");
	
	scanf("%d",&num1);

	lptr1=create(lptr1,num1);

	lptr1=reverselist(lptr1);
	printf("enter 2nd number\n");

	scanf("%d",&num1);

	lptr2=create(lptr2,num2);
	printf("ygjh\n");
	lptr2=reverselist(lptr2);
while(lptr2!=NULL)
   {
   	printf("%d",lptr2->data);
   	lptr2=lptr2->next;
	}
	/*if(num1>=num2)
	{
	 
	 lptr2=addnumber(lptr2,lptr1);
	 lptr2=reverselist(lptr2);
	 
	 }
   else
   {
    lptr2=addnumber(lptr1,lptr2);
    lptr2=reverselist(lptr2);
   }
   while(lptr2!=NULL)
   {
   	printf("%d",lptr2->data);
   	lptr2=lptr2->next;
	}*/
}
