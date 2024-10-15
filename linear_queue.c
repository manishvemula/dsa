#include<stdio.h>
#define SIZE 6
#include<stdlib.h>

struct queue{
    int arr[SIZE];
    int front;
    int rear;
};

void init_queue(struct queue *q);
int queue_full(struct queue *q);
void enqueue(struct queue *q, int data);
int queue_empty(struct queue *q);
void dequeue(struct queue *q);
int peek(struct queue *q);


int main(){
    struct queue Q;
    init_queue(&Q);
    int ch;
    do{
        printf("enter choice as 0:exit, 1:enque, 2:dequeue, 3:peek\n");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                exit(0);
            case 1:
                if(queue_full(&Q)){
                    printf("queue is full\n");
                }
                else{
                    int data;
                    printf("enter the data for inserting:\n");
                    scanf("%d",&data);
                    enqueue(&Q,data);
                }
            break;
            case 2:
            if(queue_empty(&Q)){
                printf("queue is empty\n");
            }
            else{
                int element=peek(&Q);
                dequeue(&Q);
                printf("deleted element is %d\n",element);
            }
            break;
            case 3:
            if(queue_empty(&Q)){
                printf("queue is empty\n");
            }
            else{
                int ele=peek(&Q);
                printf("topmost element is %d\n",ele);
            }
            break;
            default: printf("Invalid choice\n");
        }
    }while(ch!=0);
    return 0;
}

void init_queue(struct queue *q){
    q->front=-1;
    q->rear=-1;
}

int queue_full(struct queue *q){
    if(q->rear==SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q,int data){
    q->rear++;
    q->arr[q->rear]=data;
    if(q->front==-1)
        q->front=0;
}

int queue_empty(struct queue *q){
    if(q->front > q->rear || q->rear==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void dequeue(struct queue *q){
    q->arr[q->front]=0;
    q->front++;
}

int peek(struct queue *q){
    return q->arr[q->front];
}