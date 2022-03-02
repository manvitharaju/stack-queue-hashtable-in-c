
struct student{
    int number;
    char name[20];
};

struct hashtable{
    int size;
    int count;
    struct student* s1;
};

struct hashtable * initialize(int size);
int hashcode(struct hashtable* hash1,int key);
void insert(struct hashtable* hash1,int key,char* data);
void display(struct hashtable *hash1,int key);
int del(struct hashtable* hash1,int key);
int search(struct hashtable *hash1,int key);
