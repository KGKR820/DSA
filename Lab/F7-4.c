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
void kprint(node*p,int k){
int i=0;
     while(p!=NULL){
       if(i%k==0){
        printf(" %d -> ",p->data);
       }
       i++;
       p= p->next;
     }
     printf("NULL");
}
int main(){
node *head = NULL;
int s1;
    printf("size of list 1->");
    scanf("%d",&s1);
    inti(s1,&head);
    kprint(head,3);
    return 0;
}