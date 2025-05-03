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

void prime(node*p){
    int i=0;
    int sum =0;
    while(p != NULL){
        if(i %2 == 0){
            int y = 1;
            for(int j = 2;j < p -> data;j++){
                if((p->data) % j == 0) {
                    y = 0;
                    break;
                }
            }
            if(y==1) sum = sum + p->data; 
        }
        p = p->next;
        i++;
    }
    printf("\n%d",sum);
}
void print(node*p){
    while(p != NULL){
        printf(" %d -> ",p->data);
    p = p->next;
    }
    printf("NULL");
}
int main(){
node *head = NULL;
int s1;
    printf("size of list 1->");
    scanf("%d",&s1);
    inti(s1,&head);
    prime(head);
    return 0;
}