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

int findmin(node* p) {
    while (p->left != NULL) {
        p = p->left;
    }
    return p->data;
}

void delete(node** p, int value) {
    if (*p == NULL) {
        printf("Empty");
        return;
    }
    if (value < (*p)->data) {
        delete(&((*p)->left), value);
    } else if (value > (*p)->data) {
        delete(&((*p)->right), value);
    } else {
        if ((*p)->left == NULL) {
            node* temp = (*p)->right;
            free(*p);
            *p = temp;
        } else if ((*p)->right == NULL) {
            node* temp = (*p)->left;
            free(*p);
            *p = temp;
        } else {
            int temp = findmin((*p)->right);
            (*p)->data = temp;
            delete(&((*p)->right), temp);
        }
    }

}
int height(node *p){
    if(p == NULL){
        return 0;
    }
    else{
        int left = height(p -> left);
    int right = height(p -> right);
    return (left > right ?left:right)+1;
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
    int v;
    printf("Enter the value you wanna delete -> ");
    scanf("%d",&v);
    delete(&head,v);
    print(head);
    printf("\n");
    printf("height of the tree before insertion -> %d\n",height(head)-1);
    insert(&head,v);
    printf("height of the tree after insertion -> %d",height(head)-1);
    return 0;
}