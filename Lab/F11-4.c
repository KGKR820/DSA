#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int data;
    struct node *next;
}node;

void solution(node** Head1,node**Head2){
    node *temp1 = *Head1, *temp2 = *Head2;
    node *ext1, *ext2;
    if (!temp1) {
        *Head1 = *Head2;
        return;
    }
    if (!temp2) return;
    while (temp1 && temp2) {
        ext1 = temp1->next; 
        ext2 = temp2->next; 

        temp1->next = temp2; 
        if (!ext1) break; 

        temp2->next = ext1; 

        temp1 = ext1;
        temp2 = ext2; 
    }
    if (temp2) {
        temp1->next = temp2;
    }
}

int main(){
    int size1,size2;
    printf("size1 size2:");
    scanf("%d%d",&size1,&size2);
    node*head1=NULL,*temp1=NULL;
    node*head2=NULL,*temp2=NULL;
    while(size1--){
        node*newnode=malloc(sizeof(node));
        if(head1==NULL){
            head1=newnode;
            temp1=head1;
        }else{
           temp1->next=newnode;
           temp1=newnode;
        }
        printf("enter:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
    }
    printf("\n\n");
    while(size2--){
        node*newnode=malloc(sizeof(node));
        if(head2==NULL){
            head2=newnode;
            temp2=head2;
        }else{
           temp2->next=newnode;
           temp2=newnode;
        }
        printf("enter:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
    }

    solution(&head1,&head2);
 
    temp1=head1;
    while(temp1!=NULL){
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
}