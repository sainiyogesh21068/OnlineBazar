typedef struct node_tag{
	int data;
	struct node_tag *next;
	} node_type;
	typedef struct product_tag
	{
	  char name[20];
	  int cost;
	  int items_available;
	  int sold;

	}product_node;
typedef enum{FAILURE,SUCCESS} status_code;

status_code InsertAtStart(node_type **list_ptr,int d);
node_type* createlist(status_code *sc,int num);
node_type* DeleteAtStart(node_type *list_ptr, int *dptr, status_code *sc);
node_type* DeleteList(node_type *list_ptr,status_code *sc);
node_type* DeleteAtEnd(node_type *list_ptr,int *dptr,status_code *sc);
node_type* InsertAtEnd(node_type* list_ptr, int d, status_code *sc);
void traverse(node_type *list_ptr);
