#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "hash.h"

int main()
{
    List *test;
    int i;
    Node *temp;
    test=initialize_ht_single(5);
    assert(insert_ht_head_single(test,10,5));
    assert(insert_ht_head_single(test,40,5));
    assert(insert_ht_head_single(test,11,5));
    assert(insert_ht_head_single(test,12,5));
    assert(insert_ht_head_single(test,13,5));
    assert(insert_ht_head_single(test,20,5));
    assert(insert_ht_head_single(test,14,5));
    display_ht_single(test,5);
    return 0;
}
