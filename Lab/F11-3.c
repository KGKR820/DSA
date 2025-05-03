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
    while(p != NULL){
        printf(" %d -> ",p->data);
    p = p->next;
    }
    printf("NULL");
}
void rot(node **p,int k){
    if(k==0) return ;
    node *q =*p;
    node *temp =*p;
    while(q-> next!= NULL){
    q= q->next;
    }
    q -> next = temp;
     int count =1;
     while(count < k-1){
        temp = temp -> next;
        count ++;
     }
     *p = temp -> next;
     temp -> next = NULL;
}
int main(){
int s1;
    printf("size of list 1->");
    scanf("%d",&s1);
    node *head;
    inti(s1,&head);
    rot(&head,3);
    print(head);
    return 0;
}