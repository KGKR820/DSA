#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *N) {
    if (N == NULL)
        return 0;
    return 1 + max(height(N->left), height(N->right));
}

int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* newNode(int key) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void rightRotate(Node **y) {
    Node *x = (*y)->left;
    Node *T2 = x->right;

    x->right = *y;
    (*y)->left = T2;

    *y = x;
}

void leftRotate(Node **x) {
    Node *y = (*x)->right;
    Node *T2 = y->left;

    y->left = *x;
    (*x)->right = T2;

    *x = y;
}

void insert(Node** node, int key) {
    if (*node == NULL) {
        *node = newNode(key);
        return;
    }

    if (key < (*node)->key)
        insert(&((*node)->left), key);
    else if (key > (*node)->key)
        insert(&((*node)->right), key);
    else
        return;

    int balance = getBalance(*node);

    if (balance > 1 && key < (*node)->left->key)
        rightRotate(node);

    if (balance < -1 && key > (*node)->right->key)
        leftRotate(node);

    if (balance > 1 && key > (*node)->left->key) {
        leftRotate(&((*node)->left));
        rightRotate(node);
    }

    if (balance < -1 && key < (*node)->right->key) {
        rightRotate(&((*node)->right));
        leftRotate(node);
    }
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

void deleteNode(Node** p, int key) {
    if (*p == NULL)
        return;

    if (key < (*p)->key)
        deleteNode(&((*p)->left), key);
    else if (key > (*p)->key)
        deleteNode(&((*p)->right), key);
    else {
        if (((*p)->left == NULL) || ((*p)->right == NULL)) {
            Node *temp = (*p)->left ? (*p)->left : (*p)->right;

            if (temp == NULL) {
                temp = *p;
                *p = NULL;
            } else
                **p = *temp;
            free(temp);
        } else {
            Node* temp = minValueNode((*p)->right);
            (*p)->key = temp->key;
            deleteNode(&((*p)->right), temp->key);
        }
    }

    if (*p == NULL)
        return;

    int balance = getBalance(*p);

    if (balance > 1 && getBalance((*p)->left) >= 0)
        rightRotate(p);

    if (balance > 1 && getBalance((*p)->left) < 0) {
        leftRotate(&((*p)->left));
        rightRotate(p);
    }

    if (balance < -1 && getBalance((*p)->right) <= 0)
        leftRotate(p);

    if (balance < -1 && getBalance((*p)->right) > 0) {
        rightRotate(&((*p)->right));
        leftRotate(p);
    }
}
void printTree(Node *p) {
    if (p != NULL) {
        printTree(p->left);
        printf("%d ", p->key);
        printTree(p->right);
    }
}


int main() {
    Node *p = NULL;
    int n;
    printf("Enter the number of values -> ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        printf("E%d -> ", i + 1);
        scanf("%d", &x);
        insert(&p, x);
    }

    printf("Balance Factors after insertion:\n");
    printTree(p);

    // deleteNode(&p, 17);
    // deleteNode(&p, 83);
    // deleteNode(&p, 28);

    // printf("\nBalance Factors after deletion:\n");
    // printTree(p);

    return 0;
}