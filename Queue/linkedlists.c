#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
 struct node *next;
}node;
typedef struct queue{
    node *r;
    node* f;
}queue;
void intique(queue *p){
    p -> r = NULL;
    p -> f = NULL;
}
node * newnode(int value){
    node * ex = (node *) malloc(sizeof(node));
    ex -> data = value;
    ex -> next = NULL;
    return ex;
}
int empty(queue *p){
   return p->f == NULL; 
}
void enqueue(queue *p,int value){
    node * q = newnode(value);
    if(empty(p)){
      p -> f = q;
      p-> r = q;
    }
    else{
        p -> r -> next = q;
        p -> r = p->r->next;
    }
}
void dequeue(queue *p){
    if(empty(p)){
        printf("Empty\n");
        return;
    }
    node * temp = p ->f;
    p->f = p->f -> next;
    free(temp);
}
void display(queue *p){
      if(empty(p)){
        printf("Empty\n");
        return ;
      }
      node * a = p-> f;
      while( a != NULL){
        printf("%d -> ", a-> data);
        a = a-> next;
      }
      printf("NULL\n");
}
int main() {
    queue *q = (queue *)malloc(sizeof(queue));
    intique(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    return 0;
}