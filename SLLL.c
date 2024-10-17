#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

struct node* create_node();
void add_first(int data);
void display();
void add_last(int data);
void add_at_specific_pos(int data,int pos);
int count_nodes();
void delete_first();
void delete_last();
void delete_at_specific_pos(int pos);
void reverse();
struct node* linear_search(int key);

int main(){
    add_first(10);
    add_first(20);
    add_first(30);
    display(); //head->30->20->10
    add_last(40);
    add_last(50);
    display(); //head->30->20->10->40->50
    add_at_specific_pos(60,3);
    display(); //head->30->20->60->10->40->50
    printf("%d is number of nodes\n",count_nodes());
    delete_first();
    display(); //head->20->60->10->40->50
    delete_last();
    display(); //head->20->60->10->40
    delete_at_specific_pos(3);
    display(); //head->20->60->40
    reverse();
    display(); //head->40->60->20
    struct node* res;
    res=linear_search(60);
    if(res==NULL){
        printf("not found key\n");
    }
    else{
        printf("key found\n");
    }
    return 0;
}

struct node* create_node(){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=0;
    ptr->next=NULL;
    return ptr;
}

void add_first(int data){
    struct node *ptr=create_node();
    ptr->data=data;

    if(head==NULL){
        head=ptr;
    }
    else{
        ptr->next=head;
        head=ptr;
    }
}

void add_last(int data){
    struct node *ptr=create_node();
    ptr->data=data;

    if(head==NULL){
        head=ptr;
    } 
    else{
        struct node *travs=head;
        while(travs->next!=NULL){
            travs=travs->next;
        }
        travs->next=ptr;
    }
}

void add_at_specific_pos(int data,int pos){
    struct node *ptr=create_node();
    ptr->data=data;
    if(head==NULL){
        if(pos==1){
            add_first(data);
        }
        else{
            printf("invalid\n");
        }
    }
    else if(pos==1){
        add_first(data);
    }
    else if(pos==(count_nodes()+1)){
        add_last(data);
    }
    else if(pos<1 || pos>(count_nodes()+1)){
        printf("Invalid since pos is invalid\n");
    }
    else{
        struct node *travs=head;
        int i=1;
        while(i<pos-1){
            travs=travs->next;
            i++;
        }
        /** 
        for(int i=1;i<pos-1;i++){
            travs=travs->next;
        }
        **/
        ptr->next=travs->next;
        travs->next=ptr;
    }

}


void display(){
    if(head==NULL){
        printf("list is empty\n");
    }
    else{
    struct node *travs=head;
    printf("head");
    while(travs!=NULL){
        printf("->%d",travs->data);
        travs=travs->next;
    }
    printf("\n");
    }
}

int count_nodes(){
    int c=0;
    if(head==NULL){
        printf("empty\n");
    }
    else{
    struct node *travs=head;
    while(travs!=NULL){
        c++;
        travs=travs->next;
    }
    }
    return c;
}

void delete_first(){
    struct node *temp=head;
    if(head==NULL){
        printf("empty\n");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        head=temp->next;
        free(temp);
        temp=NULL;
    }
    
}

void delete_last(){
    
    if(head==NULL){
        printf("empty\n");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *travs=head;
        while(travs->next->next!=NULL){ //go loop till last 2 node
            travs=travs->next;
        }
        free(travs->next);
        travs->next=NULL;

    }
}

void delete_at_specific_pos(int pos){
    if(head==NULL){
        printf("empty\n");
    }
    else if(pos==1){
        delete_first();
    }
    else if(pos==count_nodes()){
        delete_last();
    }
    else if(pos<1 || pos>count_nodes()){
        printf("invalid\n");
    }
    else{
        struct node *travs=head;
        for(int i=1;i<pos-1;i++){
            travs=travs->next;
        }
        //struct node *temp=travs->next;
        travs->next=travs->next->next;   //last 2nd node of respective position
        //travs->next=temp->next;
        free(travs->next->next); 
        //free(temp);
        travs->next->next=NULL;
        //temp=NULL;
    }
}

void reverse(){
    struct node *n1=head;
    struct node *n2=head->next;
    while(n2!=NULL){
        struct node *n3=n2->next;
        n2->next=n1;
        n1=n2;
        n2=n3;
    }
    head->next=NULL;
    head=n1;
}

struct node* linear_search(int key){
    struct node* trav=head;
    while(trav!=NULL){
        if(trav->data==key){
            return trav;
        }
        trav=trav->next;
    }
    return NULL;
}