#include<stdio.h>
#include "stack.h"
#include<string.h>

void i2p(char infix[],char postfix[]);
int is_digit(char ch);
int priority(char ch);

int main()
{
    char infix[] = "5+9-4*(8-6/2)+1$(7-3)";
    char prefix[30];
    printf("Infix = %s\n",infix);
    i2p(infix,prefix);
    printf("Prefix = %s\n",prefix);
    return 0;
}

void i2p(char infix[],char prefix[]){
    char ch;
    int j=0;
    q s;
    stack_init(&s);
    for(int i=0;infix[i]!='\0';i++){
        if(is_digit(infix[i])){
            prefix[j++]=infix[i];
        }
        else if(infix[i]==')'){
            push(&s,')');
        }
        else if(infix[i]=='('){
            while(ch = peek(&s) != ')'){
                prefix[j++]=ch;
                pop(&s);
            }
            pop(&s);
        }
        else{
            while(!stack_empty(&s) && priority(peek(&s))>priority(infix[i])){
                prefix[j++]=infix[i];
                pop(&s);
            }
            push(&s,infix[i]);
        }
    }

    while(!stack_empty(&s))
    {
        prefix[j++] = peek(&s);
        pop(&s);
    }
    prefix[j] = '\0';
    strrev(prefix);
}

int is_digit(char ch){
    return ch>=48 && ch<=57;
}

int priority(char ch){
    switch(ch){
        case '+':
        case '-':
                return 8;
        case '/':
        case '%':
        case '*':
                return 9;
        case '$':
                return 10;
        default: return 0;
    }
}
