#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct product_tag
{
  char name[20];
  int cost;
  int items_available;
  int sold;
  struct product_tag *next;

}product_type;

typedef struct history_tag
{
  char product_name[20];
  int bought;
  struct history_tag *next;
}history_type;

typedef struct wish_tag
{
  char product_name[20];
  struct wish_tag *next;
}wish_type;

typedef struct customer_tag
{
  char C_ID[20];
  char name[30];
  char address[40];
  char email[50];
  char contact[15];
  //history_type *history_ptr;
  //wish_type *wish_ptr;
  int payment_history[7]; // 0-BNPL 1-COD 2-debit card 3-Credit card 4-Netbanking 5-UPI 6-Phone
  struct customer_tag *next;
}customer_type;

typedef enum{FAILURE,SUCCESS} status_code;

// customer_type* customer_intialise(customer_type* ptr)
// {
//   strcpy(ptr->C_ID,"");
//   strcpy(ptr->name,"");
//   strcpy(ptr->address,"");
//   strcpy(ptr->email,"");
//   ptr->contact=-1;
//   ptr->wish_ptr=NULL;
//   ptr->history_ptr=NULL;
//   int i=0;
//   for(;i<7;i++)
//   {
//     ptr->payment_history[i]=0;
//   }
//   ptr->next=NULL;
//   return ptr;
// }

customer_type* add_customer(customer_type** list_ptr, status_code *sc)
{

	customer_type *nptr,*ptr;
  nptr=(customer_type*)malloc(sizeof(customer_type*));
  char temp;
  //nptr=customer_intialise(nptr);

  // FILE *file_ptr;
  // if(file_ptr=fopen("E:/Projects/OnlineBazar/customer_data.txt","w"))
  // {
  //   printf("file_opened\n");
  // }
  // printf("Name : ");
  // printf("%s\n",nptr->name);
  // printf("Email : ");
  // printf("%s\n",nptr->email);
  // printf("Contact No : ");
  // printf("%d\n",nptr->contact);
  // printf("Address : ");
  // printf("%s\n",nptr->address);
  // printf("Consumer ID : ");
  // printf("%s\n",nptr->C_ID);
  //
  printf("Name : ");
  scanf("%c",&temp);
  scanf("%[^\n]",nptr->name);
  printf("Email : ");
  scanf("%c",&temp);
  scanf("%[^\n]",nptr->email);
  printf("Address : ");
  scanf("%c",&temp);
  scanf("%[^\n]",nptr->address);
  printf("Consumer ID : ");
  scanf("%c",&temp);
  scanf("%[^\n]",nptr->C_ID);
  printf("Contact No : ");
  scanf("%c",&temp);
  scanf("%[^\n]",nptr->contact);

  printf("Name : ");

  printf("%s",nptr->name);
  printf("Email : ");
  printf("%s\n",nptr->email);
  printf("Contact No : ");
  printf("%s\n",nptr->contact);
  printf("Address : ");
  printf("%s\n",nptr->address);
  printf("Consumer ID : ");
  printf("%s\n",nptr->C_ID);
  //
  // fprintf(file_ptr,"%s\n",nptr->name);
  //
  // fprintf(file_ptr,"%s\n",nptr->email);
  //
  // fprintf(file_ptr, "%lld\n",nptr->contact);
  //
  // fprintf(file_ptr, "%s\n",nptr->address);
  //
  // fprintf(file_ptr, "%s\n",nptr->C_ID);

	if(*list_ptr==NULL)
	{
		*list_ptr=nptr;
	}
	else
	{
		ptr=*list_ptr;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=nptr;
	}
  // fclose(file_ptr);
	return nptr;
}

status_code InsertAtStart(product_type **list_ptr,product_type data)
{
	product_type *nptr;
	status_code sc=SUCCESS;
	nptr=(product_type*)malloc(sizeof(product_type));
	if(nptr!=NULL)
	{
    *nptr=data;
		// nptr->data=d;
		nptr->next=*list_ptr;
		*list_ptr=nptr;
	}
	else
	{
		sc=FAILURE;
	}
	return sc;
}


product_type* createlist(status_code *sc)
{
  product_type ptr;
  FILE *fptr;
	product_type *list_ptr, *nptr;
	int i,flag=1;
	list_ptr=NULL;
  if(fptr=fopen("E:/Projects/OnlineBazar/product_data.txt","r"))
  {
  	while (!feof (fptr))
  	{
      fscanf(fptr,"%s ",ptr.name);
      fscanf(fptr,"%d ",&ptr.cost);
      fscanf(fptr,"%d ",&ptr.items_available);
      fscanf(fptr,"%d ",&ptr.sold);
  		*sc=InsertAtStart(&list_ptr,ptr);
  	}
  }
  else
  {
    printf("not opened");
  }
  fclose(fptr);
	return list_ptr;
}

void traverse_product(product_type *list_ptr)
{
	product_type *ptr;
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
      printf("%s \n",ptr->name);
      printf("%d \n",ptr->cost);
      printf("%d \n",ptr->items_available);
      printf("%d \n",ptr->sold);
			ptr=ptr->next;
		}
	}
}

void traverse_customer(customer_type *list_ptr)
{
	customer_type *nptr;
	nptr=list_ptr;
	if(list_ptr==NULL)
	{
		printf("List Empty");
	}
	else
	{
		printf("\nlist Content\n");
		while(nptr!=NULL)
		{
      printf("Name : ");
      printf("%s\n",nptr->name);
      printf("Email : ");
      printf("%s\n",nptr->email);
      printf("Contact No : ");
      printf("%d\n",nptr->contact);
      printf("Address : ");
      printf("%s\n",nptr->address);
      printf("Consumer ID : ");
      printf("%s\n",nptr->C_ID);
			nptr=nptr->next;
		}
	}
}

void main()
{
	status_code sc;
	// product_type *list_ptr;
	// list_ptr=NULL;
  //list_ptr=createlist(&sc);
  //traverse_product(list_ptr);
  customer_type *head_customer=NULL;
  customer_type *current_customer,*nptr;
  nptr=add_customer(&head_customer,&sc);
  // printf("Name : ");
  // printf("%s\n",nptr->name);
  // printf("Email : ");
  // printf("%s\n",nptr->email);
  // printf("Contact No : ");
  // printf("%d\n",nptr->contact);
  // printf("Address : ");
  // printf("%s\n",nptr->address);
  // printf("Consumer ID : ");
  // printf("%s\n",nptr->C_ID);
  traverse_customer(head_customer);
	// int data;
	// while(flag!=0){
	// printf("\t\t*****MENU****\n\t1.Create Whole List\n\t2.Delete Whole List\n\t3.Transverse\n\t4.InsertAtStart\n\t5.DeleteAtStart\n\t6.InsertAtEnd\n\t7.DeleteAtEnd\n\t8.Exit\n\tEnter Your Choice");
	// scanf("%d", &choice);
	// switch(choice)
	// {
	// 	case 1:
	// 		{
	// 			list_ptr=createlist(&sc);
	// 			break;
	// 		}
	// 	// case 2:
	// 	// 	{
	// 	// 		list_ptr=DeleteList(list_ptr,&sc);
	// 	// 		break;
	// 	// 	}
	// 	case 3:
	// 		{
	// 			traverse(list_ptr);break;
	// 		}
	// 	// case 4:
	// 	// 	{
	// 	// 		printf("Enter Data");
	// 	// 		scanf("%d",&data);
	// 	// 		sc=InsertAtStart(&list_ptr,data);break;
	// 	// 	}
	// 	// case 5:
	// 	// 	{
	// 	// 		list_ptr=DeleteAtStart(list_ptr,&data,&sc);
	// 	// 		printf("\n Deleted Data : %d",data);break;
	// 	// 	}
	// 	// case 6:
	// 	// 	{
	// 	// 		printf("Enter Data");
	// 	// 		scanf("%d",&data);
	// 	// 		list_ptr=InsertAtEnd(list_ptr,data,&sc);break;
	// 	// 	}
	// 	// case 7:
	// 	// 	{
	// 	// 		list_ptr=DeleteAtEnd(list_ptr,&data,&sc);
	// 	// 		printf("\n Deleted Data : %d",data);break;
	// 	// 	}
	// 	case 8:
	// 		{
	// 			flag=0;break;
	// 		}
	// }
	// if(flag!=0){
	// if(sc==SUCCESS)
	// {
	// 	printf("\n\n\t\tSUCCESS\t\t\n\n");
	// }
	// else
	// 	printf("\n\n\t\tFailure\t\t\n\n");
	// }
	// }
  // customer_type *nptr,*ptr;
  // nptr=(customer_type*)malloc(sizeof(customer_type*));
  //nptr=customer_intialise(nptr);
//	*sc=SUCCESS;

	// if(nptr==NULL)
	// {
	// 	*sc=FAILURE;
	// }
  // FILE *file_ptr;
  // if(file_ptr=fopen("E:/Projects/OnlineBazar/customer_data.txt","w"))
  // {
  //   printf("file_opened\n");
  // }
  // printf("Name : ");
  // printf("%s\n",nptr->name);
  // printf("Email : ");
  // printf("%s\n",nptr->email);
  // printf("Contact No : ");
  // printf("%d\n",nptr->contact);
  // printf("Address : ");
  // printf("%s\n",nptr->address);
  // printf("Consumer ID : ");
  // printf("%s\n",nptr->C_ID);
//


}
