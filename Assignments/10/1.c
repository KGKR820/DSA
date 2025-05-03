#include <stdio.h>
#include <stdlib.h>
typedef struct heap {
    int cap;
    int size;
    int *arr;
} heap;
void inti(heap **p, int s) {
    *p = (heap *)malloc(sizeof(heap));
    (*p)->cap = s;
    (*p)->size = 0;
    (*p)->arr = (int *)malloc(sizeof(int) * s);
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void maxheapify(heap *p, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < p->size && p->arr[largest] < p->arr[left]) {
        largest = left;
    }
    if (right < p->size && p->arr[largest] < p->arr[right]) {
        largest = right;
    }
    if (i != largest) {
        swap(&(p->arr[largest]), &(p->arr[i]));
        maxheapify(p, largest);
    }
}
void minheapify(heap *p, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < p->size && p->arr[smallest] > p->arr[left]) {
        smallest = left;
    }
    if (right < p->size && p->arr[smallest] > p->arr[right]) {
        smallest = right;
    }
    if (i != smallest) {
        swap(&(p->arr[smallest]), &(p->arr[i]));
        minheapify(p, smallest);
    }
}
void insertmax(heap *p, int value) {
    if (p->size == 0) {
        p->arr[0] = value;
        p->size++;
        return;
    }
    p->size++;
    int i = p->size - 1;
    p->arr[i] = value;
    while (i != 0 && p->arr[i] > p->arr[(i - 1) / 2]) {
        swap(&(p->arr[i]), &(p->arr[(i - 1) / 2]));
        i = (i - 1) / 2;
    }
}
void insertmin(heap *p, int value) {
    if (p->size == 0) {
        p->arr[0] = value;
        p->size++;
        return;
    }
    p->size++;
    int i = p->size - 1;
    p->arr[i] = value;
    while (i != 0 && p->arr[i] < p->arr[(i - 1) / 2]) {
        swap(&(p->arr[i]), &(p->arr[(i - 1) / 2]));
        i = (i - 1) / 2;
    }
}
int extractmax(heap *p) {
    if (p->size == 1) {
        p->size--;
        return p->arr[0];
    }
    int root = p->arr[0];
    p->arr[0] = p->arr[p->size - 1];
    p->size--;
    maxheapify(p, 0);
    return root;
}
int extractmin(heap *p) {
    if (p->size == 1) {
        p->size--;
        return p->arr[0];
    }
    int root = p->arr[0];
    p->arr[0] = p->arr[p->size - 1];
    p->size--;
    minheapify(p, 0);
    return root;
}
void balance(heap *max, heap *min) {
    if (max->size > min->size + 1) {
        int mx = extractmax(max);
        insertmin(min, mx);
    } else if (min->size > max->size + 1) {
        int mn = extractmin(min);
        insertmax(max, mn);
    }
}
float median(heap *max, heap *min) {
    if (max->size == min->size) {
        return (float)(max->arr[0] + min->arr[0]) / 2; 
    } else if (max->size > min->size) {
        return max->arr[0];
    } else {
        return min->arr[0];
    }
}
void add(heap *max, heap *min, int value) {
    if (max->size == 0 || max->arr[0] > value) {
        insertmax(max, value);
    } else {
        insertmin(min, value);
    }
    balance(max, min);
}
int main() {
    heap *max = NULL;
    heap *min = NULL;
    int n;
    printf("Enter the Capacity of Heaps -> ");
    scanf("%d", &n);
    inti(&max, n);
    inti(&min, n);
    for (int i = 0; i < n; i++) {
        int num;
        printf("E%d -> ", i + 1);
        scanf("%d", &num);
        add(max, min, num);
        float med = median(max, min);
    printf("Median -> %.2f\n", med); 
    }
    free(max->arr);
    free(min->arr);
    free(max);
    free(min);
    return 0;
}