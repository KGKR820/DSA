#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}
int search(int key) {
    int index = hashFunction(key);
    Node* current = hashTable[index];
    while (current) {
        if (current->key == key)
            return 1; 
        current = current->next;
    }
    return 0; 
}

void delete(int key) {
    int index = hashFunction(key);
    Node* current = hashTable[index];
    Node* prev = NULL;
    
    while (current && current->key != key) {
        prev = current;
        current = current->next;
    }
    
    if (!current) return;
    
    if (!prev) 
        hashTable[index] = current->next; 
    else 
        prev->next = current->next; 
    
    free(current);
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* current = hashTable[i];
        while (current) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                printf("%s\n", search(key) ? "Key Found" : "Key Not Found");
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}