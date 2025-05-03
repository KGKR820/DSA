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
        if (*head == NULL) {
            *head = ex;
            p=ex;
        } else { 
            p->next = ex;
            p = p->next;
        }
    }
    if (p != NULL) {
        p->next = *head;
    }
}
void print(node *p){
    node *temp = p;
   do{
    printf("%d -> ",p->data);
       p = p->next;
   }while(p != temp);
   printf("NULL\n");
}
void del(node *p,int index){
    if(index == 0){
         int k = p -> next -> data;
         p-> data = k;
         del(p,1);
      return;
    }
    else{
        int i=1;
        while(i != index){
             p = p->next;
             i++;
        }
        node *tem = p->next;
        p->next = tem->next;
        free(tem);
     }
    }
int main(){
node*head= NULL;
inti(3,&head);
print(head);
del(head,1);
print(head);
    return 0;
}