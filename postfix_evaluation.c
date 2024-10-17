#include<stdio.h>
#include "stack.h"

#include<math.h>

int is_digit(char ch){
    return ch>=48 && ch<=57;
}

int calculate(int op1, int op2, char op)
{
    switch(op)
    {
        case '*' : return op1 * op2;
        case '/' : return op1 / op2;
        case '%' : return op1 % op2;
        case '+' : return op1 + op2;
        case '-' : return op1 - op2;
        case '$' : return pow(op1,op2);
    }
}

int postfix_evaluation(char postfix[]){
    q s;
    stack_init(&s);
    for(int i=0;postfix[i]!='\0';i++){
        if(is_digit(postfix[i])){
            push(&s,postfix[i]-'0');
        }
        else{
            int op2=peek(&s);
            pop(&s);
            int op1=peek(&s);
            pop(&s);
            int res=calculate(op1,op2,postfix[i]);
            push(&s,res);
        }
    }
    int result=peek(&s);
    pop(&s);
    return result;
}

int main(){
    char postfix[] = "59+4862/-*-173-$+";
    /**for(int i=0;postfix[i]!='\0';i++)
    printf("%c\n",postfix[i]);**/
    int result = postfix_evaluation(postfix);
    printf("Result = %d\n",result);
    return 0;
}