#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "open.h"

int main()
{
    struct hashtable* hash1;
    int index;
    hash1 = init(10);
    insert(hash1, 22, "ele 22");
    insert(hash1, 2, "ele 2");
    insert(hash1, 12, "ele 12");

    index = hashcode(hash1,12);
    printf("\n 1st element in the list %d\t index: %d", hash1->node1[index].key, index);
    printf("\n 2nd element in the list %d\t index: %d", hash1->node1[index].ptr->key, index);
    printf("\n 3rd element in the list %d\t index: %d", hash1->node1[index].ptr->ptr->key, index);
    return 0;
}
