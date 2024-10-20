#include <stdio.h>
#include <string.h>
#define size 10

#define H(k) k % size
#define N_H(k) (k + 1) % size

typedef struct student {
    int rollno;
    char name[20];
} std;

void add(int rollno, const char* name);
int search(int key);
void display();
std hash_table[size];

int main() {
    add(8, "PQR");
    add(28, "MNO");
    add(2, "XYZ");
    add(3, "ABC");
    add(4, "ASD");
    add(8, "QWE");
    add(38, "DESD");
    display();

    int slot = search(38);
    if (slot == -1)
        printf("Key not Found !\n");
    else
        printf("Key found at slot = %d\n", slot);
    
    return 0;
}

void add(int rollno, const char* name) {
    std s1;
    s1.rollno = rollno;
    strncpy(s1.name, name, sizeof(s1.name) - 1);
    s1.name[sizeof(s1.name) - 1] = '\0';  // Ensure null-termination

    int slot = H(rollno);
    if (hash_table[slot].rollno == 0) {
        hash_table[slot] = s1;
        return;
    }
    if (hash_table[slot].rollno == rollno) {
        strncpy(hash_table[slot].name, name, sizeof(hash_table[slot].name) - 1);
        hash_table[slot].name[sizeof(hash_table[slot].name) - 1] = '\0';  // Ensure null-termination
        return;
    } else {
        int new_slot = slot;
        for (int i = 0; i < size; i++) {
            new_slot = N_H(new_slot);
            if (hash_table[new_slot].rollno == 0) {
                hash_table[new_slot] = s1;
                return;
            }
            if (hash_table[new_slot].rollno == rollno) {
                strncpy(hash_table[new_slot].name, name, sizeof(hash_table[new_slot].name) - 1);
                hash_table[new_slot].name[sizeof(hash_table[new_slot].name) - 1] = '\0';  // Ensure null-termination
                return;
            }
        }
    }
}

int search(int key) {
    int slot = H(key);
    if (hash_table[slot].rollno == key) {
        return slot;
    } else {
        int new_slot = slot;
        for (int i = 0; i < size; i++) {
            new_slot = N_H(new_slot);
            if (hash_table[new_slot].rollno == key) {
                return new_slot;
            }
        }
    }
    return -1;
}

void display() {
    for (int i = 0; i < size; i++) {
        printf("[%d] : %d - %s\n", i, hash_table[i].rollno, hash_table[i].name);
    }
}
