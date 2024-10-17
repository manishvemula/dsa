#include<stdio.h>
#include "stack.h"
#include<string.h>
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

int prefix_evaluation(char prefix[]){
    q s;
    stack_init(&s);
    for(int i =strlen(prefix)-1 ;i>=0;i--){
        if(is_digit(prefix[i])){
            push(&s,prefix[i]-'0');
        }
        else{
            int op1=peek(&s);
            pop(&s);
            int op2=peek(&s);
            pop(&s);
            int res=calculate(op1,op2,prefix[i]);
            push(&s,res);
        }
    }
    int result=peek(&s);
    pop(&s);
    return result;
}

int main(){
    char prefix[] = "+-+59*4-8/62$1-73";
    /**for(int i=0;postfix[i]!='\0';i++)
    printf("%c\n",postfix[i]);**/
    int result = prefix_evaluation(prefix);
    printf("Result = %d\n",result);
    return 0;
}