#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "student_hash.h"

int main()
{
    struct hashtable * hash1;
    hash1=initialize(5);
    insert(hash1,10,"manvitha");
    insert(hash1,11,"shreya");
    insert(hash1,12,"ram");
    insert(hash1,30,"manvi");
    insert(hash1,40,"manvi");
    //display(hash1,30);
    assert(search(hash1,30)==3);
    display(hash1,30);

    return 0;
}
