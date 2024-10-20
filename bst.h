#ifndef __BST_H
#define __BST_H

typedef struct node{
    struct node* left;
    int data;
    struct node *right;
    int visited;
}node;

node* create_node();
void add_node(int data);
void rec_inorder(node *trav);
void rec_preorder(node *trav);
void rec_postorder(node *trav);
void bst_preorder();
void bst_inorder();
void bst_postorder();
void bfs_traversal();
node* bfs_search_key(int key);
void dfs_traversal();
node* dfs_search_key(int key);

#endif /*__BST_H*/