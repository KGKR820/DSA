#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* create(int value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(node** p, int value) {
    if (*p == NULL) {
        *p = create(value);
    } else if (value < (*p)->data) {
        insert(&((*p)->left), value);
    } else {
        insert(&((*p)->right), value);
    }
}
void print(node* p) {
    if (p != NULL) {
        print(p->left);
        printf("%d ", p->data);
        print(p->right);
    }
}
int main() {
    int n;
    node* head = NULL;
    printf("Enter the number of values -> ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        printf("E%d -> ", i);
        scanf("%d", &x);
        insert(&head, x);
    }
    print(head);
    printf("\n");

    return 0;
}