#include<stdio.h> 
#include<stdlib.h> 

 
typedef struct dlnode_tag
{ 
	int data; 
	struct dlnode_tag *prev;
	struct dlnode_tag* next; 
}dlnode_type; 


dlnode_type *dlmakenode(int data) 
{ 
	dlnode_type *new_node = ( dlnode_type *) malloc(sizeof(dlnode_type)); 
	new_node->data = data;
	new_node->prev = NULL; 
	new_node->next = NULL; 
	return new_node; 
} 
dlnode_type *insert(dlnode_type *dlptr,int d)
{
	dlnode_type *nptr;
	nptr = dlmakenode(d);
	nptr->next = dlptr;
	if(dlptr!=NULL)
	{
		dlptr->prev = nptr;
	
	}
	dlptr = nptr;
	return dlptr;
}
void reverseprint(dlnode_type* dlptr)
{   
	while(dlptr->next != NULL)
	{
		dlptr = dlptr->next;
	}
    
    while(dlptr != NULL) 
	{ 
		printf("%d", dlptr->data); 
		if(dlptr ->prev) 
			printf(" "); 
		dlptr = dlptr->prev; 
	} 
	printf("\n"); 
	 
	
}
int main(void)
{
	dlnode_type* dlptr = NULL;
	insert(&dlptr,6);
	insert(&dlptr,7);
	insert(&dlptr,5);
	insert(&dlptr,8);
	reverseprint(dlptr);
	
}

