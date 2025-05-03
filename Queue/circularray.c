#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10
typedef struct queue{
    int f;
    int r;
    int arr[MAX];
} queue;

void intiqueue(queue *p){
    p->f = -1;
    p->r = -1;
}
int size(queue *p){
    if (p->f == -1)
        return 0;
    return (p->r - p->f + MAX) % MAX + 1;
}
int empty(queue *p){
    return p->f == -1;
}
int full(queue *p){
    return (p->r + 1) % MAX == p->f;
}
void enqueue(queue *p, int data){
    if (full(p)){
        printf("Full\n");
        return;
    }
    if (empty(p)){
        p->f = 0;
    }
    p->r = (p->r + 1) % MAX;
    p->arr[p->r] = data;
}
void dequeue(queue *p){
    if (empty(p)){
        printf("Empty\n");
        return;
    }
    if (p->f == p->r){
        p->f = -1;
        p->r = -1;
    }
    else{
        p->f = (p->f + 1) % MAX;
    }
}
void display(queue *p){
    if (empty(p)){
        printf("Empty\n");
        return;
    }
    int i = p->f;
    while (true){
        printf("%d ", p->arr[i]);
        if (i == p->r)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main(){
    queue *p = (queue *)malloc(sizeof(queue));
    intiqueue(p);
    enqueue(p, 9);
    enqueue(p, 7);
    enqueue(p, 3);
    display(p);
    dequeue(p);
    display(p);
    enqueue(p, 5);
    enqueue(p, 6);
    display(p);
    return 0;
}