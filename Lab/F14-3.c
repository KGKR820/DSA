#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 100
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

void initializeStack(Stack *s)
{
    s->top = NULL;
}

int isEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    Node *temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
} 

int evaluatePostfix(char *expression)
{
    Stack s;
    initializeStack(&s);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            int num = 0;
            while (isdigit(expression[i]))
            {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            push(&s, num);
        }
        else if (expression[i] == '_')
        {
            int base = pop(&s);
            int exponent = 0;
            i++;
            while (isdigit(expression[i]))
            {
                exponent = exponent * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            push(&s, (int)pow(base, exponent));
        }
        else if (strchr("+-*/", expression[i]))
        {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (expression[i])
            {
            case '+':
                push(&s, operand1 + operand2);
                break;
            case '-':
                push(&s, operand1 - operand2);
                break;
            case '*':
                push(&s, operand1 * operand2);
                break;
            case '/':
                push(&s, operand1 / operand2);
                break;
            }
        }
    }
    return pop(&s);
}

int main()
{
    char expression[SIZE];
    printf("Enter a postfix expression: ");
    fgets(expression, SIZE, stdin);
    expression[strcspn(expression, "\n")] = '\0';
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}