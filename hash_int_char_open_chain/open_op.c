#include<stdio.h>
#include<stdlib.h>
#include "open.h"

struct hashtable* init(int size)
{
    int i;
    struct hashtable* hash1;
    hash1=(struct hashtable*)malloc(sizeof(struct hashtable));
    hash1->node1=(struct node*)malloc((sizeof(struct node))*size);
    hash1->size=size;
    for(i=0;i<hash1->size;i++)
    {
        strcpy(hash1->node1[i].data,"");
        hash1->node1[i].key=-1;
        hash1->node1[i].ptr=NULL;
    }
    return hash1;
}

struct node* get_node(int key,char* data)
{
    struct node* node1;
    node1=(struct node*)malloc(sizeof(struct node));
    strcpy(node1->data,data);
    node1->key=key;
    node1->ptr=NULL;
    return node1;
};

int hashcode(struct hashtable* hash1,int key)
{
    return (key%hash1->size);
}

void insert(struct hashtable* hash1,int key,char* data)
{
    struct node* temp1;
    temp1=get_node(key,data);
    int index;
    index=hashcode(hash1,key);
    struct node*temp;
    temp=&hash1->node1[index];
    if(temp->key==-1)
    {
        strcpy(hash1->node1[index].data,(temp1->data));
        hash1->node1[index].key = (temp1->key);
        hash1->node1[index].ptr = (temp1->ptr);
    }
    else
    {
    while(temp->ptr != NULL)
    {
        temp = temp->ptr;
    }
    temp->ptr = temp1;
    }
    printf("\n First element in the list %d\n", temp1->key);

}

