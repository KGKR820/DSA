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
int commonanc(node* p, int v1, int v2) {
    if (p == NULL) {
        return -1;
    }
    if (v1 < p->data && v2 < p->data) {
        return commonanc(p->left, v1, v2);
    } else if (v1 > p->data && v2 > p->data) {
        return commonanc(p->right, v1, v2);
    } else {
        return p->data;
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
    int v1, v2;
    printf("Enter two values to find their common ancestor -> ");
    scanf("%d %d", &v1, &v2);
    int ancestor = commonanc(head, v1, v2);
    if (ancestor != -1) {
        printf("Common ancestor -> %d\n", ancestor);
    } else {
        printf("No common ancestor found.\n");
    }
    return 0;
}