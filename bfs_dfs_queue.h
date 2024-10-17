#ifndef __Queue_H
#define __Queue_H

#define size 30
#include"bst.h"

typedef struct Queue
{
    struct node *arr[size]; // int arr[SIZE]
    int rear;
    int front;
}queue;


void init_queue(queue *pq);
void enqueue(queue *pq, struct node* data);
void dequeue(queue *pq);
struct node* Peek(queue *pq);
int queue_full(queue *pq);
int queue_empty(queue *pq);

#endif