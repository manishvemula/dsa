#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

struct queue{
    int a[SIZE];
    int front;
    int rear;
};

void cir_init_queue(struct queue *q);
int cir_queue_empty(struct queue *q);
void cir_enqueue(struct queue *q,int data);
int cir_queue_full(struct queue *q);
void cir_dequeue(struct queue *q);
int cir_peek(struct queue *q);

int main(){
    struct queue Q;
    cir_init_queue(&Q);
    int ch;
    do{
        printf("enter choice as 0:exit, 1:enque, 2:dequeue, 3:peek\n");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                exit(0);
            case 1:
                if(cir_queue_full(&Q)){
                    printf("queue is full\n");
                }
                else{
                    int data;
                    printf("enter the data for inserting:\n");
                    scanf("%d",&data);
                    cir_enqueue(&Q,data);
                    printf("entered data: %d\n",data);
                }
            break;
            case 2:
            if(cir_queue_empty(&Q)){
                printf("queue is empty\n");
            }
            else{
                int element=cir_peek(&Q);
                cir_dequeue(&Q);
                printf("deleted element is %d\n",element);
            }
            break;
            case 3:
            if(cir_queue_empty(&Q)){
                printf("queue is empty\n");
            }
            else{
                int ele=cir_peek(&Q);
                printf("topmost element is %d\n",ele);
            }
            break;
            default: printf("Invalid choice\n");
        }
    }while(ch!=0);
    return 0;
}

void cir_init_queue(struct queue *q){
    q->front=-1;
    q->rear=-1;
}

int cir_queue_empty(struct queue *q){
    return q->rear==-1;
}   

void cir_enqueue(struct queue *q,int data){
    q->rear=(q->rear+1)%SIZE;
    q->a[q->rear]=data;
    if(q->front==-1)
        q->front=0;
}

int cir_queue_full(struct queue *q){
    return q->front==(q->rear+1)%SIZE;
    
}

void cir_dequeue(struct queue *q){
    if(q->front == q->rear)
    {
        q->a[q->front] = 0;
        q->rear = q->front = -1;
    }
    else
    {
        // optional
        q->a[q->front] = 0;
        q->front = (q->front+1) % SIZE;
    }
}

int cir_peek(struct queue *q){
    return q->a[q->front];
}

