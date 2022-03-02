#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct _node_{
    int data;
    struct _node_ *ptr;
};
typedef struct _node_ Node;

struct _linked_list_
{
    Node *head,*tail;
    int count;
    int op_status;
    int operations;//keep track of the transcations-->debit or credit
};

typedef struct _linked_list_ List;

List *initialize()
{
    List *my_list;
    my_list=(List *)malloc(sizeof(List));
    if(my_list==NULL)return NULL;
    my_list->head=my_list->tail=NULL;
    my_list->count=0;
    return my_list;
}

Node *get_node(int data)
{
    Node *newnode;
    newnode=(Node *)malloc(sizeof(Node));
    newnode->data=data;
    newnode->ptr=NULL;
    return newnode;
}
//insert at any position
int insert_after_pos(List *my_list,int data,int pos)
{
    Node *newnode,*temp;
    int i=1;
    newnode=get_node(data);
    if(newnode==NULL)return NULL;
    if(my_list->count==0)
    {
        my_list->head=my_list->tail=newnode;
    }
    if(pos<1 || pos>my_list->count)
    {
        return NULL;
    }
    else{
        temp=my_list->head;
        while(i<pos)
        {
            temp=temp->ptr;
            i++;
        }
        newnode->ptr=temp->ptr;
        temp->ptr=newnode;
    }
    my_list->count++;
    my_list->operations++;
    return 1;
}

//delete at any position

int insert_beg(List *my_list,int data)
{
    Node *newnode;
    newnode=get_node(data);
    if(newnode==NULL)return 0;
    if(my_list->count==0)//check if list is empty
    {
        my_list->head=my_list->tail=newnode;
        my_list->head=newnode;
    }
    else{
        newnode->ptr=my_list->head;
        my_list->head=newnode;
    }
    my_list->count++;
    //my_list->operations++;
    return 1;
}

//delete the data from begining
void delete_specified(List *my_list,int loc)
    {
        Node *temp, *temp1;
        int i;
        temp=my_list->head;
        for(i=0;i<loc;i++)
        {
            temp1 = temp;
            temp = temp->ptr;

            if(temp == NULL)
            {
                printf("\nThere are less than %d elements in the list..\n",loc);
                return;
            }
        }
        temp1 ->ptr = temp->ptr;
        free(temp);
        my_list->count--;
        my_list->operations++;
        printf("\nDeleted %d located node \n ",loc);
    }

 //stack_delete at begining
int delete_beg(List *my_list)
{
    Node *temp;
    if(my_list->head==NULL && my_list->tail==NULL)
    {
        return 0;
    }
    if(my_list->head==my_list->tail)//one node
    {
        free(my_list->head);
        my_list->head=my_list->tail=NULL;
    }
    else{
        temp=my_list->head;
        my_list->head=my_list->head->ptr;
        free(temp);
    }
    my_list->count--;
    return 1;
    //my_list->operations++;
}

//stack push
int push(List *stack,int data)
{
    return insert_beg(stack,data);
}

int pop(List *stack)
{
    return delete_beg(stack);
}
int display_stack(List *s)
{
    Node *temp;
    temp=s->head;
    for(temp=s->head;temp!=NULL;temp=temp->ptr)
    {
        printf("%d ",temp->data);
    }
    printf("\n");
    return 1;
}

int undo_all_transactions(List *s)
{
    for(int i=0;i<s->operations;i++)
    {
        pop(s);
    }

}

int main()
{
    List *test;
    test=initialize();
    insert_beg(test,10);
    insert_beg(test,20);
    insert_beg(test,30);
    insert_beg(test,40);
    insert_beg(test,50);
    insert_beg(test,60);
    insert_after_pos(test,12,3);
    insert_after_pos(test,13,6);
    delete_specified(test,2);
    //undo_all_transactions(test);
     display_stack(test);
     undo_all_transactions(test);
     display_stack(test);
     assert(test->count==0);


}
