#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
node* create(int value){
    node * temp = (node* )malloc(sizeof(node));
    temp -> data = value;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}
void insert(node** p, int value) {
    if (*p == NULL) {
        *p = create(value);
    } else if ((*p)->data > value) {
        insert(&((*p)->left), value);
    } else {
        insert(&((*p)->right), value);
    }
}

node* findMin(node* p) {
    while (p->left != NULL) {
        p = p->left;
    }
    return p;
}
void delete(node** p, int value) {
    if (*p == NULL) return;

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
            node* temp = findMin((*p)->right);
            (*p)->data = temp->data;
            delete(&((*p)->right), temp->data);
        }
    }
}
void search(node *p,int value){
    if(p == NULL) printf("\nNot Found");
    else{
        if(p -> data == value){
            printf("\nFound");
        }
        else if(p -> data > value){
            search(p-> left,value);
        }
        else if(p -> data < value){
            search(p-> right,value);
        }
        
    }
}
void print(node *p){
if(p != NULL){
    print(p -> left);
    printf("%d ",p -> data);
    print(p -> right);
}
}
int main(){
  node *head = NULL;
  insert(&head,9);
  insert(&head,4);
   insert(&head,12);
//    delete(&head,9);
   print(head);
   search(head,4);
   search(head,8);
    return 0;
}