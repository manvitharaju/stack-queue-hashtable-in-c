#include<stdio.h>
#include<stdlib.h>
#include "hash.h"

List *initialize_ht_single(int size)
{
    List *ht;
    int i;
    ht=(List *)malloc(sizeof(List)*size);
    for(i=0;i<size;i++)
    {
        (ht+i)->head=NULL;
        (ht+i)->count=0;
        (ht+i)->tail=NULL;
    }
    return ht;
}

//hash function
int hash(int data,int size)
{
    return(data%size);
}
//insert node at head of linked list
int insert_node_head(List *myList, int data)
{
    Node *newNode;
    newNode=getNode(data);
    if(newNode==NULL)
        return 0;
    if(myList->count==0)
        myList->head=myList->tail=newNode;
    else{
        newNode->ptr=myList->head;
        myList->head=newNode;
    }
    myList->count++;
    return 1;
}
//create a new node
Node *getNode(int data)
{
    Node * newNode;
    newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->ptr=NULL;
    return newNode;
}

//insert into hash table single pointer
int insert_ht_head_single(List *ht,int data,int size){
    int index=hash(data,size);
    List *myList;
    myList=&ht[index];
    return insert_node_head(myList,data);
}

//display the hash table single pointer

void display_ht_single(List *ht,int size)
{
    Node *temp;
    int i;
    for(i=0;i<size;i++)
    {
        temp=(ht+i)->head;
        printf("Index[%d]:",i);
        while(temp!=NULL)
        {
            printf("%d \t",temp->data);
            temp=temp->ptr;
        }
        printf("\n");
    }
}
