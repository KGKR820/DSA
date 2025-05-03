#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100

typedef struct stack {
    char items[SIZE];
    int top;
} stack;

void create(stack *s) {
    s->top = -1;
}

bool empty(stack *s) {
    return s->top == -1;
}

void push(stack *s, char value) {
        s->items[++(s->top)] = value;
}

char pop(stack *s) {
    if (empty(s)) {
        printf("stack underflow!\n");
        return '\0';
    } else {
        return s->items[(s->top)--];
    }
}

char top(stack *s) {
    if (empty(s)) {
        printf("stack is empty\n");
        return '\0';
    } else {
        return s->items[s->top];
    }
}

bool pair(char op, char cl) {
    if (op == '(' && cl == ')') return true;
    if (op == '{' && cl == '}') return true;
    if (op == '[' && cl == ']') return true;
    return false;
}
bool check(char* s) {
    stack stack;
    create(&stack);

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(&stack, s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (empty(&stack) || !pair(pop(&stack), s[i])) {
                return false;
            }
        }
    }
    return empty(&stack);
}

int main() {
    char input[SIZE];
    printf("Enter a string of brackets: ");
    scanf("%s", input);
    if (check(input)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is invalid.\n");
    }
    return 0;
}