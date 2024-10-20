#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "bst_stack.h"
#include"bfs_dfs_queue.h"

node *root=NULL;


int main(){

    add_node(50);
    add_node(25);
    add_node(66);
    add_node(88);
    add_node(20);
    add_node(22);
    add_node(90);
    add_node(50);
    add_node(80);
    add_node(36);

    printf("\nin order: \n");
    rec_inorder(root);
    printf("\npre order: \n");
    rec_preorder(root);
    printf("\npost order: \n");
    rec_postorder(root);
    printf("\n bst preorder: \n");
    bst_preorder(root);
    printf("\n bst inorder: \n");
    bst_inorder(root);
    printf("\n bst postorder: \n");
    bst_postorder(root);
    printf("\n bfs traversal: \n");
    bfs_traversal(root);
    node *result=bfs_search_key(80);
    
    if(result==NULL){
        printf("\nkey not found\n");
    }
    else{
       printf("key found is %d\n",result->data);
    }
    printf("\n dfs traversal: \n");
    dfs_traversal(root);
    node *res=bfs_search_key(80);
    
    if(result==NULL){
        printf("\nin dfs key not found\n");
    }
    else{
       printf("in dfs key found is %d\n",res->data);
    }
    return 0;
}
node* create_node(){
    node *nn=(node *)malloc(sizeof(node));
    nn->data=0;
    nn->left=NULL;
    nn->right=NULL;
    nn->visited=0;
}

void add_node(int data){
    node *nn=create_node();
    nn->data=data;
    if(root==NULL){
        root=nn;
    }
    else{
        node *trav=root;

        while(1){
            if(data<trav->data){
                if(trav->left==NULL){
                    trav->left=nn;
                    break;
                }
                else{
                    trav=trav->left;
                }
            }
            else{
                if(trav->right==NULL){
                    trav->right=nn;
                    break;
                }
                else{
                    trav=trav->right;
                }
            }
        }
    }
}

void rec_inorder(node *trav){
    if(trav==NULL){
        return;
    }
    rec_inorder(trav->left);
    printf("%4d",trav->data);
    rec_inorder(trav->right);
}

void rec_preorder(node *trav){
    if(trav==NULL){
        return;
    }
    printf("%4d",trav->data);
    rec_preorder(trav->left);
    rec_preorder(trav->right);
}

void rec_postorder(node *trav){
    if(trav==NULL){
        return;
    }
    rec_postorder(trav->left);
    rec_postorder(trav->right);
    printf("%4d",trav->data);
}

void bst_preorder(){
    stack s;
    stack_init(&s);
    node *trav=root;
    while(trav!=NULL || !stack_empty(&s)){
    while(trav!=NULL){
        printf("%4d",trav->data);
        
        if(trav->right!=NULL){
            push(&s,trav->right);
        }
        trav=trav->left;
    }
        if(!stack_empty(&s)){
            trav=peek(&s);
            pop(&s);
        }
    
    }      
}

void bst_inorder(){
    stack s;
    stack_init(&s);
    node *trav=root;
    while(trav!=NULL || !stack_empty(&s)){
        while(trav!=NULL){
            push(&s,trav);
            trav=trav->left;
        }
        if(!stack_empty(&s)){
            trav=peek(&s);
            pop(&s);
        }
        printf("%4d",trav->data);
        trav=trav->right;
    }
}

void bst_postorder(){
    stack s;
    stack_init(&s);
    node *trav=root;
    while(trav!=NULL || !stack_empty(&s)){
        while(trav!=NULL){
            push(&s,trav);
            trav=trav->left;
        }
        if(!stack_empty(&s)){
            trav=peek(&s);
            pop(&s);
        }
        if(trav->right==NULL || trav->right->visited==1){
            printf("%-4d",trav->data);
            trav->visited=1;
            trav=NULL;
        }
        else{
            push(&s,trav);
            trav=trav->right;
        }
        
    }
}

void bfs_traversal(){
    queue q;
    init_queue(&q);
    node *trav=root;
    enqueue(&q,trav);
    while(!queue_empty(&q)){
        trav=Peek(&q);
        dequeue(&q);
    printf("%4d",trav->data);
    if(trav->left!=NULL){
        enqueue(&q,trav->left);
    }
    if(trav->right!=NULL){
        enqueue(&q,trav->right);
    }
    }

}

node* bfs_search_key(int key){
    queue q;
    init_queue(&q);
    node *trav=root;
    enqueue(&q,trav);
    while(!queue_empty(&q)){
        trav=Peek(&q);
        dequeue(&q);
    if(key==trav->data){
        return trav;
    }
    if(trav->left!=NULL){
        enqueue(&q,trav->left);
    }
    if(trav->right!=NULL){
        enqueue(&q,trav->right);
    }
    }
    return NULL;
}

void dfs_traversal(){
    stack s;
    stack_init(&s);
    push(&s,root);
    while(!stack_empty(&s)){
        node* trav=peek(&s);
        pop(&s);
        printf("%4d",trav->data);
        if(trav->left!=NULL){
            push(&s,trav->left);
        }
        if(trav->right!=NULL){
            push(&s,trav->right);
        }
        
    }
}

node* dfs_search_key(int key){
    stack s;
    stack_init(&s);
    push(&s,root);
    while(!stack_empty(&s)){
        node* trav=peek(&s);
        pop(&s);
        if(key==trav->data)
        return trav;
        if(trav->left!=NULL){
            push(&s,trav->left);
        }
        if(trav->right!=NULL){
            push(&s,trav->right);
        }
        
    }
    return NULL;
}