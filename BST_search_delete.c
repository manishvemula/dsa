#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* add_node(struct node* trav, int data) {
    if (trav == NULL) {
        trav = create_node(data);
    } else if (data < trav->data) {
        trav->left = add_node(trav->left, data);
    } else {
        trav->right = add_node(trav->right, data);
    }
    return trav;
}

void in_order(struct node *trav)
{   
    if(trav == NULL)
        return;

    in_order(trav->left);
    printf("%4d",trav->data);
    in_order(trav->right);

}

struct node* bst_search_key(int key){
    struct node* trav=root;
    
    while(trav!=NULL){
        if(key==trav->data){
            return trav;
        }
        if(key<trav->data){
            trav=trav->left;
        }
        else{
            trav=trav->right;
        }
    }
    return NULL;

}

struct node* search_with_parent(int key, struct node **pparent){
    struct node *trav=root;
    *pparent=NULL;
    while(trav!=NULL){
        if(key==trav->data){
            return trav;
        }
        *pparent=trav;
        if(key<trav->data)
        trav=trav->left;
        else
        trav=trav->right;
    }
    *pparent=NULL;
    return trav;
}

void delete_node(int key){
    struct node *parent;
    struct node *temp=search_with_parent(5,&parent);
    if(temp==NULL){
        printf("node does not exit\n");
    }
    else{
        if(temp->left!=NULL && temp->right!=NULL){
            struct node *pre=temp->left;
            parent=temp;
            while(pre->right!=NULL){
                parent=pre;
                pre=pre->right;
            }
            temp->data=pre->data;
            temp=pre;
        }
        if(temp->left==NULL){
            if(temp==root){
                root=temp->right;
            }
            else if(temp==parent->left){
                parent->left=temp->right;
            }
            else{
                parent->right=temp->right;
            }
        }
        else{
            if(temp==root){
                root=temp->left;
            }
            else if(temp==parent->left){
                parent->left=temp->left;
            }
            else{
                parent->right=temp->left;
            }
        }
    }
    free(temp);
    temp=NULL;

}

int main() {
    root = NULL; 
    root = add_node(root, 2);
    root = add_node(root, 3);
    root = add_node(root, 4);
    root = add_node(root, 5);
    root = add_node(root, 6);
    root = add_node(root, 7);
    root = add_node(root, 8);
    printf("\nin order: \n");
    in_order(root);
    delete_node(7);
    printf("\nin order after delete: \n");
    in_order(root);
    printf("\nNodes added to the tree.\n");
    struct node *parent;
    struct node *res=search_with_parent(7,&parent);
    if(res==NULL){
        printf("\nnot found\n");
    }
    else{
        printf("\n%d is parent key\n ",parent->data);
    }

    struct node *travs=bst_search_key(7);
    if(travs==NULL){
        printf("\nnot found\n");
    }
    else{
        printf("\n %d is key\n ",travs->data);
    }
    return 0;
}

