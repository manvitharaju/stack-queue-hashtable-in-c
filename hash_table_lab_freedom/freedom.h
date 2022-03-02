

struct list{
struct node* head, *tail;
int count;
};

struct list* list_in_table[26];

struct node{
char* word;
char* meaning;
char* part_of_speech;

struct node* ptr;
};

struct list* init();

struct node* get_node(char* word, char* meaning, char* part_of_speech);

void insert_element(struct list* list1, char* word, char* meaning, char* part_of_speech);

int hashkey(char* word);

void display_all(struct list* list1);

void display(char* word);
