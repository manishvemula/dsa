#define SIZE 20

typedef struct stack{
    struct node *a[SIZE];
    int top;
}stack;

int stack_init(stack *s);
struct node* peek(stack *s);
void push(stack *s, node* data);
void pop(stack *s);
int stack_full(stack *s);
int stack_empty(stack *s);





