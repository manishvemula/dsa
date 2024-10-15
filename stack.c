#include "stack.h"
#define SIZE 5
int stack_init(q *s){
    s->top=-1;
}
int peek(q *s){
    return s->a[s->top];
}

void push(q *s,int data){
        s->top++;
        s->a[s->top]=data;
}

void pop(q *s){
        s->a[s->top]=0;
        s->top--;
}

int stack_full(q *s){
    return s->top==SIZE-1;
}

int stack_empty(q *s){
    return s->top==-1;
}