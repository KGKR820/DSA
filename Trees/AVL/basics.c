#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
int max(int a ,int b){
    return a>b ?a:b;
}
int height(node *p){
    return p ==NULL ? 0: max(height(p -> left),height(p -> right)) + 1;
}
node * create(int value){
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = value;
    temp -> right = NULL;
    temp -> left = NULL;
    return temp;
}
int balfac(node *p){
    return (height(p->left)) - (height(p->right));
}
void rightrot(node **p){
    node *a = (*p) -> left;
    node *b = a -> right;
    a -> right = *p;
    (*p) -> left = b;
    *p = a;
}
void leftrot(node **p){
    node *a = (*p) -> right;
    node *b = a -> left;
    a -> left = *p;
    (*p) -> right = b;
    *p = a;
}
void insert(node **p,int value){
   if(*p == NULL){
    *p = create(value);
    return;
   }
    else if(value < (*p) -> data){
        insert(&((*p) -> left),value);
    }
    else if(value > (*p) -> data){
        insert(&((*p) -> right),value);
    }
    else{
        return;
    }
    int bal = balfac(*p);
  if(bal > 1 && (*p) -> left -> data  > value){
     rightrot(p);
  }
  if(bal < -1 && (*p) -> right -> data  < value){
    leftrot(p);
 }
 if(bal > 1 && (*p) -> left -> data  < value){
    leftrot(&((*p) -> left));
    rightrot(p);
 }
 if(bal < -1 && (*p) -> right -> data  > value){
    rightrot(&((*p) -> right));
    leftrot(p);
 }
}
node * findmin(node *p){
    while (p->left != NULL) {
        p = p->left;
    }
    return p;
}
void delete(node **p,int value){
   if(*p == NULL){
    return;
   }
   else if(value < (*p) -> data){
    delete(&((*p) -> left),value);
   }
   else if(value > (*p) -> data){
    delete(&((*p) -> right),value);
   }
   else{
    if((*p) -> left == NULL){
        node *temp = (*p) -> right;
        free(*p);
        *p = temp;
    }
    else if((*p) -> right == NULL){
        node *temp = (*p) -> left;
        free(*p);
        *p = temp;
    }
    else{
      node* t = findmin((*p) -> right);
      (*p) -> data = t -> data;
       delete(&((*p) -> right),t ->data);
    }
   }
   if (*p == NULL)
        return;

    int bal = balfac(*p);

    if (bal > 1 && balfac((*p)->left) >= 0)
        rightrot(p);

    if (bal > 1 && balfac((*p)->left) < 0) {
        leftrot(&((*p)->left));
        rightrot(p);
    }

    if (bal < -1 && balfac((*p)->right) <= 0)
        leftrot(p);

    if (bal < -1 && balfac((*p)->right) > 0) {
        rightrot(&((*p)->right));
        leftrot(p);
    }

}
void print(node *p) {
    if (p != NULL) {
        print(p->left);
        printf("%d ", p->data);
        print(p->right);
    }
}
int main(){
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
    return 0;
}