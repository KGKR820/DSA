#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
 struct node *next;
}node;
typedef struct queue{
    node *r;
    node *f;
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
      p->r -> next = p-> f;
    }
    else{
        p -> r -> next = q;
        p -> r = p->r->next;
        p->r -> next = p-> f;
    }
}
void dequeue(queue *p){
    if(empty(p)){
        printf("Empty\n");
        return;
    }
    node *temp = p->f;
    if (p->f == p->r) {
        p->f = NULL;
        p->r = NULL;
    } else {
        p->f = p->f->next;
        p->r->next = p->f;
    }
    free(temp);
}
void display(queue *p){
      if(empty(p)){
        printf("Empty\n");
        return ;
      }
      node * a = p-> f;
      do{
        printf("%d -> ", a-> data);
        a = a-> next;
      }while( a != p->f);
      printf("%d\n",p->f ->data);
}
int main() {
    queue *q = (queue *)malloc(sizeof(queue));
    intique(q);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    dequeue(q);
    display(q);
    return 0;
}