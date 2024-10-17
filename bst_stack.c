#include "bst.h"
#include "bst_stack.h"
#define SIZE 20
int stack_init(stack *sp){
    sp->top=-1;
}

struct node* peek(stack *sp){
    return sp->a[sp->top];
}

void push(stack *sp,node* data){
        sp->top++;
        sp->a[sp->top]=data;
}

void pop(stack *sp){
        sp->a[sp->top]=0;
        sp->top--;
}

int stack_full(stack *sp){
    return sp->top==SIZE-1;
}

int stack_empty(stack *sp){
    return sp->top==-1;
}