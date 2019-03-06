
  
#include <stdio.h> 
#include <stdlib.h> 
  
// A linked List Node 
 typedef struct Node 
{ 
    int data; 
    struct Node* next; 
} node; 
void push(struct Node** head_ref, int new_data) 
{ 
    
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d  ", node->data); 
        node = node->next; 
    } 
    printf("  ended"); 
} 
void swapPointer(node** a, node** b ) 
{ 
    node* t = *a; 
    *a = *b; 
    *b = t; 
} 
int getSize(struct Node *node) 
{ 
    int size = 0; 
    while (node != NULL) 
    { 
        node = node->next; 
        size++; 
    } 
    return size; 
} 
  
 
node* addSameSize(node* head1, node* head2, int* carry) 
{ //checking size
    if (head1 == NULL) 
        return NULL; 
  
    int sum; 
  
    //allocate memory 
    node* result = (node *) malloc(sizeof(node)); 
  
    
    result->next = addSameSize(head1->next, head2->next, carry); 
    sum = head1->data + head2->data + *carry; 
    *carry = sum / 10; 
    sum = sum % 10; 
  
    // Assigne the sum to current node of resultant list 
    result->data = sum; 
  
    return result; 
} 
  
 
void addCarryToRemaining(node* head1, node* cur, int* carry, node** result) 
{ 
    int sum; 
  
    // If diff. number of nodes are not traversed, add carry 
    if (head1 != cur) 
    { 
        addCarryToRemaining(head1->next, cur, carry, result); 
  
        sum = head1->data + *carry; 
        *carry = sum/10; 
        sum %= 10; 
  
        // add this node to the front of the result 
        push(result, sum); 
    } 
} 
  
// The main function that adds two linked lists represented by head1 and head2. 
// The sum of two lists is stored in a list referred by result 
void addList(node* head1, node* head2, node** result) 
{ 
    node *cur; 
  
    // first list is empty 
    if (head1 == NULL) 
    { 
        *result = head2; 
        return; 
    } 
  
    // second list is empty 
    else if (head2 == NULL) 
    { 
        *result = head1; 
        return; 
    } 
  
    int size1 = getSize(head1); 
    int size2 = getSize(head2) ; 
  
    int carry = 0; 
  
    // Add same size lists 
    if (size1 == size2) 
        *result = addSameSize(head1, head2, &carry); 
  
    else
    { 
        int diff = abs(size1 - size2); 
  
        // First list should always be larger than second list. 
        // If not, swap pointers 
        if (size1 < size2) 
            swapPointer(&head1, &head2); 
  
        // move diff. number of nodes in first list 
        for (cur = head1; diff--; cur = cur->next); 
  
        // get addition of same size lists 
        *result = addSameSize(cur, head2, &carry); 
  
        // get addition of remaining first list and carry 
        addCarryToRemaining(head1, cur, &carry, result); 
    } 
  
    // if some carry is still there, add a new node to the fron of 
     
    if (carry) 
        push(result, carry); 
} 
  

int main() 
{ 
    node *head1 = NULL, *head2 = NULL, *result = NULL; 
  
    int arr1[] = {1, 1, 9,1,2,3,3,4,5,5,6,7,7,7,8,8,9,9,9,0}; 
    int arr2[] = {1, 9,1}; 
  
    int size1 = sizeof(arr1) / sizeof(arr1[0]); 
    int size2 = sizeof(arr2) / sizeof(arr2[0]); 
  
    // Create first list 
    int i; 
    for (i = size1-1; i >= 0; --i) 
        push(&head1, arr1[i]); 
  
    // Create second list  
    for (i = size2-1; i >= 0; --i) 
        push(&head2, arr2[i]); 
  
    addList(head1, head2, &result); 
  
    printList(result); 
  
    return 0; 
} 
