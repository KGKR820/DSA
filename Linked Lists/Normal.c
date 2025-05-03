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
            p = p->next;
        }
    }
}
void insert(node **p,int index,int data){
    node *ex = (node *)malloc(sizeof(node));
    ex-> data = data;
    node *q = *p;
    if(index ==0){
        ex -> next = *p;
        *p = ex;
    }
    else{
        int i=0;
         while(i != index-1){
            q=q->next;
            i++;
         }
      node *temp = q ->next;
      q -> next = ex;
       ex -> next = temp;

    }
}

// void insert(node *p,int index,int data){
//     node *ex = (node *)malloc(sizeof(node));
//     ex-> data = data;
//     if(index ==0){
//        int k = p -> data;
//        p-> data = data;
//        insert(p,1,k);
//     }
//     else{
//         int i=0;
//          while(i != index-1){
//             p=p->next;
//             i++;
//          }
//       node *temp = p ->next;
//       p -> next = ex;
//        ex -> next = temp;

//     }
// }

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
// void del(node *p,int index){
//     if(index == 0){
//          int k = p -> next -> data;
//          p-> data = k;
//          del(p,1);
//       return;
//     }
//     else{
//         int i=1;
//         while(i != index){
//              p = p->next;
//              i++;
//         }
//         node *tem = p->next;
//         p->next = tem->next;
//         free(tem);
//      }
//     }
void print(node*p){
    while(p != NULL){
        printf(" %d -> ",p->data);
    p = p->next;
    }
    printf("NULL");
}
void search(node*p,int s){
   int m =0 ;
    while(p != NULL){
        if(p->data == s){
            m = 1;
            break;
        }
        p = p->next;
    }
    (m==0)?printf("\nFalse"):printf("\nTrue");
}
int main(){
node *head = NULL;
inti(3,&head);
insert(&head,1,4);
print(head);
del(&head,2);
printf("\n");
print(head);
search(head,9);
    return 0;
}