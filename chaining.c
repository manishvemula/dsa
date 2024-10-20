#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

#define H(k) k % SIZE

typedef struct student {
    int roll_no;
    char name[20];
} std_entry;

typedef struct node {
    std_entry entry;
    struct node *next;
} node;

struct list {
    struct node *head;
};

struct list hash_table[SIZE];

struct node* create_node();
void add(int roll_no, const char* name);
void init_list();
void display();

int main() {
    init_list();
    add(8, "PQR");
    add(28, "MNO");
    add(2, "XYZ");
    add(3, "ABC");
    add(4, "ASD");
    add(8, "QWE");
    add(38, "DESD");
    display();
    return 0;
}

void init_list() {
    for (int i = 0; i < SIZE; i++) {
        hash_table[i].head = NULL;
    }
}

struct node* create_node() {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->entry.roll_no = 0;
    strcpy(new_node->entry.name, "");
    new_node->next = NULL;
    return new_node;
}

void add(int roll_no, const char* name) {
    int slot = H(roll_no);
    struct node *new_node;

    if (hash_table[slot].head == NULL) {
        new_node = create_node();
        new_node->entry.roll_no = roll_no;
        strncpy(new_node->entry.name, name, sizeof(new_node->entry.name) - 1);
        new_node->entry.name[sizeof(new_node->entry.name) - 1] = '\0';  // Ensure null-termination
        hash_table[slot].head = new_node;
        return;
    }

    if (hash_table[slot].head->entry.roll_no == roll_no) {
        strncpy(hash_table[slot].head->entry.name, name, sizeof(hash_table[slot].head->entry.name) - 1);
        hash_table[slot].head->entry.name[sizeof(hash_table[slot].head->entry.name) - 1] = '\0';  // Ensure null-termination
        return;
    }

    struct node *trav = hash_table[slot].head;
    while (trav != NULL) {
        if (trav->entry.roll_no == roll_no) {
            strncpy(trav->entry.name, name, sizeof(trav->entry.name) - 1);
            trav->entry.name[sizeof(trav->entry.name) - 1] = '\0';  // Ensure null-termination
        }
        if (trav->next == NULL) {
            new_node = create_node();
            new_node->entry.roll_no = roll_no;
            strncpy(new_node->entry.name, name, sizeof(new_node->entry.name) - 1);
            new_node->entry.name[sizeof(new_node->entry.name) - 1] = '\0';  // Ensure null-termination
            trav->next = new_node;
            return;
        }
        trav = trav->next;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]:", i);
        if (hash_table[i].head != NULL) {
            struct node *trav = hash_table[i].head;
            while (trav != NULL) {
                printf("%d-%s =>", trav->entry.roll_no, trav->entry.name);
                trav = trav->next;
            }
        }
        printf("\n");
    }
}
