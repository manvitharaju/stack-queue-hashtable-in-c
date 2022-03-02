#include <stdio.h>
#include <stdlib.h>
#include "freedom.h"

int main()
{
      int i;
    for(i=0;i<26;i++)
    {
        list_in_table[i] = init();
    }

    int key;
    key = hashkey("freedom");

    insert_element(list_in_table[key], "Freedom", "the power or right to act, speak, or think as one wants.","noun");

    key = hashkey("apple");

    insert_element(list_in_table[key], "apple", "the round fruit of a tree of the rose family, which typically has thin green or red skin and crisp flesh.","noun");

    key = hashkey("work");

    insert_element(list_in_table[key], "work", "a task or tasks to be undertaken.","noun");

    key = hashkey("play");

    insert_element(list_in_table[key], "play", "engage in activity for enjoyment and recreation rather than a serious or practical purpose.","verb");

    key = hashkey("female");

    insert_element(list_in_table[key], "Female", "women","noun");


    printf("\nDisplaying all the words \n");

    for(i=0;i<26;i++)
    {
        if(list_in_table[i]->head!=NULL)
        {
        display_all(list_in_table[i]);
        printf("\n");
        }
    }

    printf("\n\n\n\nSearch for the word 'play'\n");
    display("play");
    return 0;
}
