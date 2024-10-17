#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

node *head=NULL;
node *tail=NULL;

void add_first(int data);
node* create_node();
void add_last(int data);
void backward_Display();
void forward_display();
void add_at_specific_pos(int data, int pos);
int count_nodes();
void delete_first();
void delete_last();
void delete_at_specific_pos(int pos);


int main()
{
    add_first(40);
    add_first(35);
    add_first(20);
    add_last(95);
    add_last(50);
    add_first(60);
    forward_display();
    backward_Display();
    // head->60->20->35->40->95->50
    // Tail->50->95->40->35->20->60
    add_at_specific_pos(80,4);
    forward_display();
    backward_Display();
    // head->60->20->35->80->40->95->50
    // Tail->50->95->40->80->35->20->60

    delete_first();
    forward_display();
    backward_Display();
    // head->20->35->80->40->95->50
    // Tail->50->95->40->80->35->20

    delete_last();
    forward_display();
    backward_Display();
    // head->20->35->80->40->95
    // Tail->95->40->80->35->20

    delete_at_specific_pos(3);
    forward_display();
    backward_Display();
    // head->20->35->40->95
    // Tail->95->40->35->20


    return 0;
}

node* create_node()
{
   node *nn=(node *)malloc(sizeof(node));
   if(nn==NULL){
    printf("malloc failed\n");
   }
   else{
   nn->data=0;
   nn->next=NULL;
   nn->prev=NULL;
   }
   return nn;
}

void add_first(int data)
{
    node *nn=create_node();
    nn->data=data;
    if(head==NULL){
        head=nn;
        tail=nn;
    }
    else{
        nn->next=head;
        head->prev=nn;
        head=nn;
    }
    
}

void add_last(int data){
    node *new_node = create_node();

    new_node->data = data;
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}

void forward_display()
{
    if(head == NULL)
    {
        printf("List is Empty !\n");
    }
    else
    {
        node *travs=head;
        printf("head");
        while(travs!=NULL){
            printf("->%d",travs->data);
            travs=travs->next;
        }
        printf("\n");
    }
}

void backward_Display()
{
    if(head == NULL)
    {
        printf("List is Empty !\n");
    }
    else
    {
        node *travs=tail;
        printf("tail");
        while(travs!=NULL){
            printf("->%d",travs->data);
            travs=travs->prev;
        }
        printf("\n");
    }
}

void add_at_specific_pos(int data, int pos)
{
   if(head == NULL)
    {
        if(pos==1)
            add_first(data);
        else
            printf("Invalid !\n");
    }
    else if(pos == 1)
        add_first(data);
    else if(pos == count_nodes()+1)
        add_last(data);
    else if(pos < 1 || pos > count_nodes() + 1)
        printf("Invalid !\n");
    else
    {
        struct node *new_node = create_node();
        new_node->data = data;

        node *trav = head;
        for(int i =1; i<pos-1; i++)
        {
            trav = trav->next;
        }
        new_node->prev = trav;
        new_node->next = trav->next;
        trav->next = new_node;
        new_node->next->prev = new_node;
    }
}

int count_nodes()
{
    int count = 0;
    if(head == NULL)
        printf("List is Empty !\n");
    else
    {
        struct node *trav = head;

        while(trav != NULL)
        {
            count++;
            trav = trav->next;
        }
    }
    return count;
}

void delete_first()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *temp = head;
        head = head->next; // or head = temp->next
        head->prev = NULL;
        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head == NULL)
        printf("Lis is Empty !\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *temp = tail;
        tail = temp->prev;
        tail->next = NULL;

        free(temp);
        temp = NULL;
    }
}

void delete_at_specific_pos(int pos)
{
    if(head == NULL)
        printf("List is Empty !\n ");
    else if(pos == 1)
        delete_first();
    else if(pos == count_nodes())
        delete_last();
    else if(pos < 1 || pos > count_nodes())
        printf("Invalid !\n");
    else
    {
        node *trav = head;
        for(int i =1; i<pos; i++)
        {
            trav = trav->next;
        }
        trav->prev->next = trav->next;
        trav->next->prev = trav->prev;

        free(trav);
        trav = NULL;
    }
}