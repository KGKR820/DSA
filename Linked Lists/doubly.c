#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node*prev;
    struct node *next;
     int data;
}node;
void inti(node **head,int size){
   int i=0;
   node *p = NULL;
    for(int i=0;i<size;i++){
        node *ex = (node *)malloc(sizeof(node));
        ex -> next = NULL;
        ex -> prev = p;
        printf("e%d -> ",i+1);
        scanf("%d",&ex -> data);
        if(*head ==NULL){
            *head = ex;
            p = ex;
        }
        else{
            p -> next = ex;
            p = p-> next;
        }
    }
}
    void print(node *head) {
        node *p = head;
        while (p != NULL) {
            printf("%d -> ", p->data);
            p = p->next;
        }
        printf("NULL\n");
    }
void delete(node **head,int k){
    node *p = *head;
    if(k==0){
        (*head)->next->prev = NULL;
        node * t = *head;
        *head = p-> next;
        free(t);
    }
    else{
        int i=0;
        while(i != k-1){
            p = p-> next;
            i++;
        }
        node * t = p-> next;
        p -> next = t -> next;
        t -> next -> prev = p;
        free(t);
    }
}
int main() {
        node *head = NULL;
        inti(&head, 4);
        print(head);
        delete(&head,2);
        print(head);
        return 0;
    }