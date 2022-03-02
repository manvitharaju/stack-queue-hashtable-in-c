
#include "freedom.h"
#define NULL 0

struct list* init()
{
    struct list* list1;

    list1 = (struct list*)malloc(sizeof(struct list));
    list1->count = 0;
    list1->head = list1->tail = NULL;

    return list1;
}

struct node* get_node(char* word, char* meaning, char* part_of_speech)
{
    struct node* node1;
    node1 = (struct node*)malloc(sizeof(struct node));
    node1->meaning = meaning;
    node1->word = word;
    node1->part_of_speech = part_of_speech;
    node1->ptr = NULL;
    return node1;
}

void insert_element(struct list* list1, char* word, char* meaning, char* part_of_speech)
{
    struct node* node1;
    node1 = get_node(word,meaning,part_of_speech);

    if(list1->count == 0)
    {
        list1->head = list1->tail = node1;
        list1->count++;
    }
    else
    {
        list1->tail->ptr = node1;
        list1->tail = node1;
        list1->count++;
    }

}

int hashkey(char* word)
{
    int i;
    i = *word - 'a';  // Will produce values from 0 to 25 for 'a' to 'z' respectively. Ex - if word is "hat" then, *word is 'h' whose ASCII value is 104. so, (*word - 'a') i.e, 104-97 =  7 will be index/key of the words starting with letter h.
    return i;
}

void display_all(struct list* list1)
{
    struct node* node1;

    node1 = list1->head;

    while(node1!= NULL)
    {
        printf("\n Word : %s \n Meaning : %s \n Parts of speech : %s", node1->word, node1->meaning, node1->part_of_speech);
        node1 = node1->ptr;
    }
}

void display(char* word)
{
    int key;
    key = hashkey(word);
    struct node* node1;
    node1 = list_in_table[key]->head;

    while(node1!=NULL)
    {
        if(!strcmp(node1->word,word))
        {
            printf("\n Word : %s \n Meaning : %s \n Parts of speech : %s", node1->word, node1->meaning, node1->part_of_speech);
            break;
        }
        node1 = node1->ptr;
    }
}
