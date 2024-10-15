#include<stdio.h>
#include"stack.h"
#include<stdlib.h>

int main(){
    q s;
    stack_init(&s);
    int ch;
    do{
        printf("enter choice as 0:exit, 1:enque, 2:dequeue, 3:peek\n");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                exit(0);
            case 1:
                if(stack_full(&s)){
                    printf("stack is full\n");
                }
                else{
                    int data;
                    printf("enter the data for inserting:\n");
                    scanf("%d",&data);
                    push(&s,data);
                    printf("entered data: %d\n",data);
                }
            break;
            case 2:
            if(stack_empty(&s)){
                printf("stack is empty\n");
            }
            else{
                int element=peek(&s);
                pop(&s);
                printf("deleted element is %d\n",element);
            }
            break;
            case 3:
            if(stack_empty(&s)){
                printf("stack is empty\n");
            }
            else{
                int ele=peek(&s);
                printf("topmost element is %d\n",ele);
            }
            break;
            default: printf("Invalid choice\n");
        }
    }while(ch!=0);
    return 0;
}
