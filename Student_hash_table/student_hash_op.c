#include<stdio.h>
#include<stdlib.h>
#include "student_hash.h"

struct hashtable * initialize(int size)
{
    struct hashtable* hash1;
    int i;
    hash1=(struct hashtable*)malloc(sizeof(struct hashtable));
    hash1->s1=(struct student*)malloc(sizeof(struct student)*size);
    hash1->size=size;
    hash1->count=0;
    for(i=0;i<size;i++)
    {
        hash1->s1[i].number=-1;
        strcpy(hash1->s1[i].name,"");
    }
    return hash1;
}

int hashcode(struct hashtable* hash1,int key)
{
    return(key%hash1->size);
}


//insert data

void insert(struct hashtable* hash1,int key,char* data)
{
    int index;
    index=hashcode(hash1,key);
    while(hash1->s1[index].number!=-1)
    {
        index++;
        index=index%(hash1->size);
    }
    strcpy(hash1->s1[index].name,data);
    hash1->s1[index].number=key;
    //printf("\n ..insert ... \n key:%d \nData:%s\n index:%d\n",hash1->s1[index].number,hash1->s1[index].name,index);

}
//to display

void display(struct hashtable *hash1,int key)
{
    int index,i;
    index=hashcode(hash1,key);
    while(hash1->s1[index].number!=key && hash1->s1[index].number!=-1)
    {
        index++;
        index=index%(hash1->size);
        i++;
        if(i>(hash1->size))
        {
            printf("\n Element not found to display \n");
            break;
        }
    }
    if(hash1->s1[index].number==key)
        printf("\n ..display ... \n key:%d \nData:%s\n index:%d\n",hash1->s1[index].number,hash1->s1[index].name,index);
    else
        printf("\n element not found to display\n");
}

//delete element

int del(struct hashtable* hash1,int key)
{
    int index,i=0;
    index=search(hash1,key);
    if(hash1->s1[index].number==key)
    {
        hash1->s1[index].number=-1;
        strcpy(hash1->s1[index].name,"");
        printf("\n Element not found to delete");
        printf("\n ..deleting ... \n key:%d \nData:%s\n index:%d\n",hash1->s1[index].number,hash1->s1[index].name,index);
    }
    return 1;
}

int search(struct hashtable *hash1,int key)
{
    int index;
    index=hashcode(hash1,key);
    while(hash1->s1[index].number!=key && hash1->s1[index].number!=-1)
    {
        index++;
        index=index%(hash1->size);
    }
     if(hash1->s1[index].number==key)
    {
        printf("\n ..searching... \n key:%d \nData:%s\n index:%d\n",hash1->s1[index].number,hash1->s1[index].name,index);
        return index;
    }
    else{
        printf("\n not found \n");
        return -1;
    }
}
