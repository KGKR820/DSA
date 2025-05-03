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
void mid(node *p){
    node *fast = p;
    node *slow = p;
    while( fast != NULL &&fast -> next !=NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    printf("Mid element -> %d",slow -> data);
}
int main(){
int s1;
    printf("size of list 1->");
    scanf("%d",&s1);
    node *head;
    inti(s1,&head);
     mid(head);
    return 0;
}