#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
void inti(int size,node **head){
    node *p = NULL;
    for(int i=0;i<size;i++){
        node *ex = malloc(sizeof(node));
        printf("e%d -> ",i+1);
        scanf("%d",&ex -> data);
        ex-> next = NULL;
        if (*head == NULL) {
            *head = ex;
            p=ex;
        } else {
            p->next = ex;
            p = ex;
        }
    }
}
void print(node*p){
    if(p != NULL){
        printf("Element -> %d\n",p->data);
    p = p->next;
    print(p);
    }
}
int main(){
int s1,s2;
    printf("size of list 1->");
    scanf("%d",&s1);
    printf("size eof list 2->");
    scanf("%d",&s2);
    node *h1 = NULL;
    node *h2 = NULL;
    inti(s1,&h1);
    print(h1);
    inti(s2,&h2);
    print(h2);
    return 0;
}