#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head=NULL;

node *create_node();
void add_first(int data);
void display();
void add_last(int data);
int count_nodes();
void delete_first();
void delete_last();
void reverse();

int main(){
    add_first(10);
    add_first(20);
    add_first(30);
    display(); //head->30->20->10
    add_last(40);
    add_last(50);
    display(); //head->30->20->10->40->50
    printf("%d is number of nodes\n",count_nodes());
    delete_first();
    display(); //head->20->10->40->50
    delete_last();
    display(); //head->20->10->40
    reverse();
    display(); //head->40->10->20
    return 0;
}

node *create_node(){
    node *new_node=(node *)malloc(sizeof(node));
    new_node->data=0;
    new_node->next=NULL;
    return new_node;
}

void add_first(int data){
    node *new_node=create_node();
    new_node->data=data;
    if(head==NULL){
        head=new_node;
        new_node->next=head;
    }
    else{
        node *travs=head; 
        while(travs->next!=head){
            travs=travs->next;
        } 
        new_node->next=head;
        head=new_node;
        travs->next=head;
    }
}

void display(){
    if(head==NULL){
        printf("empty\n");
    }
    else{
        node *travs=head;
        printf("Hello");
    do{
        printf("->%d",travs->data);
        travs=travs->next;
    }while(travs!=head);
    }
    printf("\n");
}

void add_last(int data){
    node *n_n=create_node();
    n_n->data = data;

    if(head == NULL)
    {
        head = n_n;
        n_n->next = head;
    }
    else
    {
    node *travs=head;
    while(travs->next!=head){
        travs=travs->next;
    }
    travs->next=n_n;
    n_n->next=head;
    }
}

int count_nodes(){
    int c=0;
    if(head==NULL){
        printf("empty\n");
    }
    else{
    node *trav=head;
    while(trav->next!=head){
        trav=trav->next;
        c++;
    }
    }
    return c;
}

void delete_first(){
    if(head == NULL)
        printf("List is Empty !\n");
    else if(head->next==head){
        free(head);
        head=NULL;
    }
    else{
        node *trav=head;
        while(trav->next!=head){
            trav=trav->next;
        }
        /**head=trav->next->next;
        trav->next=head;
        free(trav->next);
        trav->next=NULL;**/
        node *temp = head;

        head = temp->next;

        trav->next = head;

        free(temp);
        temp = NULL;
    }
}

void delete_last(){
    if(head == NULL)
        printf("List is Empty !\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
    node *trav=head;
    while(trav->next->next!=head){
        trav=trav->next;
    }
    free(trav->next);
    trav->next=head;
    }
}

void reverse(){
    node *n1=head;
    node *n2=head->next;
    while(n2!=head){
        node *n3=n2->next;
        n2->next=n1;
        n1=n2;
        n2=n3;
    }
    head->next=head;
    head=n1;
}