#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100
typedef struct stack{
    int stack[SIZE];
    int top;
} stack;
 
typedef struct {
    stack main;
    stack min;
} minstack;

void create(stack *s){
    s->top = -1;
}
bool isEmpty(stack *s){
    return s->top == -1;
}
void push(stack *s, int value){
    if (s->top < SIZE - 1){
        s->stack[++(s->top)] = value;
    }
    else{
        printf("Stack overflow\n");
    }
}
int pop(stack *s){
    if (!isEmpty(s)){
        return s->stack[(s->top)--];
    }
    else{
        printf("Stack underflow\n");
        return -1; 
    }
}
int top(stack *s){
    if (!isEmpty(s)){
        return s->stack[s->top];
    }
    else{
        printf("Stack is empty\n");
        return -1; 
    }
}
void pushSpecial(minstack *ss, int value){
    push(&ss->main, value);
    if (isEmpty(&ss->min) || value <= top(&ss->min)){
        push(&ss->min, value);
    }
}
int topSpecial(minstack *ss){
    return top(&ss->main);
}
int getMin(minstack *ss){
    return top(&ss->min);
}
int main(){
    minstack ss;
    create(&ss.main);
    create(&ss.min);
    pushSpecial(&ss, 10);
    pushSpecial(&ss, 20);
    pushSpecial(&ss, 5);
    pushSpecial(&ss, 30);
    printf("Minimum element: %d\n", getMin(&ss));
    return 0;
}