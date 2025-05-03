#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void inti(int size, node **head) {
    node *p = NULL;
    for (int i = 0; i < size; i++) {
        node *ex = malloc(sizeof(node));
        printf("e%d -> ", i + 1);
        scanf("%d", &ex->data);
        ex->next = NULL;
        if (*head == NULL) {
            *head = ex;
            p = ex;
        } else {
            p->next = ex;
            p = ex;
        }
    }
}

void print(node *p) {
    while (p != NULL) {
        printf(" %d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void insertEnd(node **head, int data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertBegn(node **head, int data) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void clear(node **head) {
    node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void k_reversed(node **head, int k) {
    if (k <= 1 || *head == NULL) return;

    node *current = *head;
    node *prevTail = NULL;
    node *newHead = NULL;

    while (current != NULL) {
        node *groupHead = NULL;
        node *groupTail = current;
        int count = 0;

        while (current != NULL && count < k) {
            node *next = current->next;
            current->next = groupHead;
            groupHead = current;
            current = next;
            count++;
        }

        if (newHead == NULL) {
            newHead = groupHead;
        } else {
            prevTail->next = groupHead;
        }

        prevTail = groupTail;
    }

    *head = newHead;
}

int main() {
    int s1;
    printf("size of list 1->");
    scanf("%d", &s1);
    node *head = NULL;
    inti(s1, &head);
    printf("Original list:\n");
    print(head);
    k_reversed(&head, 3);
    printf("List after k-reversed:\n");
    print(head);
    clear(&head);
    return 0;
}