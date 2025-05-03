#include <stdio.h>
#define size 100
typedef struct stack{
    int arr[size];
     int top;
}stack;
void create(stack *p){
    p -> top = -1;
}
void push(stack *p,int d){
    (p->top)++;
    p->arr[p->top] = d;
}
void pop(stack *p) {
    p->top  = p->top -1;
}
void peek(stack *p){
    printf("%d",p -> arr[p->top]);
}
int main (){
stack a;
create(&a);
push(&a,6);
push(&a,7);
peek(&a);
pop(&a);
peek(&a);
push(&a,9);
peek(&a);
    return 0;
}