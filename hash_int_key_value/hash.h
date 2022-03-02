
struct _node_
{
    int data;
    struct _node_ *ptr;
};

typedef struct _node_ Node;

struct _linkedlist_
{
    Node *head,*tail;
    int count;
};

typedef struct _linkedlist_ List;

List *initialize_ht_single(int);
List *initialize_ht_single(int);
int insert_node_head(List *myList, int data);
Node *getNode(int data);
int insert_ht_head_single(List *ht,int data,int size);
void display_ht_single(List *ht,int size);
