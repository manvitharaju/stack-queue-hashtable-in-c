#include <stdio.h>
#include <stdlib.h>


#define MAX 10

int count=0;
struct stack{
    int data[MAX];
    int top;
};
typedef struct stack stack;

void createEmptyStack(stack *s){
    s->top=-1;
}

//check if stack is full
int isFull(stack *s){
    if(s->top==MAX-1)
        return 1;
    else
        return 0;
}

//check if stack is empty
int isEmpty(stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
//push elements into stack
stack push(stack *s,int data)
{
    if(isFull(s)){
        printf("STACK FULL\n");
    }else{
        s->top++;
        s->data[s->top]=data;
    }
    count++;
}

//pop elements from stack
stack pop(stack *s){
    if(isEmpty(s)){
        printf("Stack Empty\n ");
    }else{
        printf(" undo %d",s->data[s->top]);
        s->top--;
    }
    count--;
    printf("\n");
}

//print elements of stack
void printStack(stack *s)
{
    printf("Stack: ");
    for(int i=0;i<count;i++)
    {
        printf("%d\t",s->data[i]);
    }
}
void undo(stack *s,stack *s1){
    //printf("%d",s->data[s->top]);
   // push(s1,s->data[s->top]);
    redo(s1,s->data[s->top]);
    pop(s);
}

void redo(stack *s1,int data)
{
     push(s1,data);
}

int main()
{
    stack *st=(stack *)malloc(sizeof(stack));
    stack *sredo=(stack *)malloc(sizeof(stack));
    createEmptyStack(st);
    createEmptyStack(sredo);
    push(st,10);
    push(st,20);
    push(st,30);
    push(st,40);
    push(st,50);
    printStack(st);
    undo(st,sredo);
    undo(st,sredo);
    undo(st,sredo);
    undo(st,sredo);
    undo(st,sredo);
    printStack(sredo);
    return 0;
}
