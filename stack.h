#define SIZE 5

typedef struct stack{
    int a[SIZE];
    int top;
}q;

int stack_init(q *s);
int peek(q *s);
void push(q *s, int data);
void pop(q *s);
int stack_full(q *s);
int stack_empty(q *s);




