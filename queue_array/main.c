#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define EMPTY 0
#define FULL 3

struct queue{
    int front,rear,size;
    int capacity;
    int *array;
};

struct queue *create_queue(int capacity)
{
    struct queue *queue=(struct queue*)malloc(sizeof(struct queue));
    queue->capacity=capacity;
    queue->front=queue->size=0;
    queue->rear=queue->capacity-1;
    queue->array=(int*)malloc(queue->capacity*sizeof(int));
    return queue;
};
//check if queue is full
int isFull(struct queue *queue)
{
    return (queue->size==queue->capacity);
}
//queue is empty when size=0
int isEmpty(struct queue *queue)
{
    return (queue->size==0);
}
//enqueue
int enqueue(struct queue* queue,int element)
{
    if(isFull(queue))
        return FULL;
    queue->rear=(queue->rear+1)%queue->capacity;
    queue->array[queue->rear]=element;
    queue->size=queue->size+1;
    printf("%d enqueued to queue \n ",element);
    return 1;
}
//dequeue
int dequeue(struct queue *queue)
{
    if(isEmpty(queue))
        return EMPTY;
    int item=queue->array[queue->front];
    queue->front=(queue->front+1)%queue->capacity;
    queue->size=queue->size-1;
    return item;
}

//function to get front of the queue
int front(struct queue *queue)
{
    if(isEmpty(queue))
        return EMPTY;
    return queue->array[queue->front];
}

//function to get rear of queue
int rear(struct queue *queue)
{
    if(isEmpty(queue))
        return EMPTY;
    return queue->array[queue->rear];
}

int display(struct queue * queue)
{
    if(isEmpty(queue))
        return EMPTY;
    for(int i=0;i<queue->size;i++)
    {
        printf("%d ",queue->array[i]);
    }
    printf("\n");
    return 1;
}
int main()
{
    struct queue *q;
    q=create_queue(5);
    assert(q->front==0);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    display(q);
    assert(front(q)==1);
    assert(enqueue(q,6)==3);
    dequeue(q);
    dequeue(q);
    display(q);
    enqueue(q,30);
    enqueue(q,44);
    enqueue(q,56);
    display(q);
    return 0;
}
