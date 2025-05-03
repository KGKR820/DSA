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
    printf("NULL\n");
}
void del(node **p,int index){
    node *temp = *p;
    node *q = *p;
    if(index ==1){
      *p = temp -> next;
      free(temp);
      return;
    }
    else{
        int i=1;
        while(i != index-1){
             q = q->next;
             i++;
        }
        node *tem = q->next;
        q->next = tem->next;
        free(tem);
     }
    }
void compdel(node *p){
        node *temp = p->next;
        int i=0;
        while(temp!=NULL){
            if(p->data < temp -> data){
                del(&p,i+1);
             }
             else{
                 i++;
             }
             p = p-> next;
             temp = temp -> next;
        }
     }
int main(){
node *head = NULL;
int s1;
    printf("size of list 1->");
    scanf("%d",&s1);
    inti(s1,&head);
    compdel(head);
    print(head);
    return 0;
}