#include <stdio.h>
#include <stdlib.h>
typedef struct heap{
    int size;
    int cap;
    int *arr;
}heap;
void inti(heap**p,int m){
    *p = (heap *)malloc(sizeof(heap));
  (*p) -> size = 0;
  (*p) -> cap = m;
  (*p) -> arr = (int*)malloc(sizeof(int)*m);
}
void swap(int *a,int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
void maxheapify(heap *p,int i){
   int largest = i;
  int left = 2*i +1;
  int right = 2*i +2;
  if(left < p -> size && p ->arr[left] > p ->arr[largest]){
     largest = left;
  }
  if(right < p -> size && p -> arr[right] > p -> arr[largest]){
    largest = right;
  }
  if(i != largest){
    swap(&(p -> arr[largest]),&(p -> arr[i]));
    maxheapify(p,largest);
  }
}
void buildmaxheap(heap *p,int brr[],int siz){
  if(siz > p -> cap){
    printf("Overflow");
    return;
  }
  for(int i=0;i<siz;i++){
    p -> arr[i] = brr[i];
  }
  p -> size = siz;
  for(int i = (siz/2)-1;i>=0;i--){
    maxheapify(p,i);
  }
}
// The insert function in your code is used to add a new element to the max heap while maintaining the max heap property
void insert(heap *p,int value){
    if(p -> size == p-> cap){
        printf("Array is full\n");
        return;
    }
    p -> size ++;
   int i = p-> size-1;
   p -> arr[i] = value;
   while (i != 0 && p->arr[(i - 1) / 2] < p->arr[i]) {
    swap(&p->arr[(i - 1) / 2], &p->arr[i]);
    i = (i - 1) / 2;
}
}
void deleteRoot(heap *p){
  if (p->size <= 0) {
      printf("Heap is empty\n");
      return;
  }
  if (p->size == 1) {
      printf("Deleted root: %d\n", p->arr[0]);
      p->size--;
      return;
  }

  // Store the root value to print later
  int root = p->arr[0];

  // Replace the root with the last element
  p->arr[0] = p->arr[p->size - 1];
  p->size--;

  // Restore the max heap property
  maxheapify(p, 0);

  // Print the deleted root value
  printf("Deleted root: %d\n", root);
}

// void heapsort(heap*q){
//   if(q -> size == 0){
//     printf("Empty");
//     return;
//   }
//   if(q -> size ==1){
//     printf("%d ",q -> arr[0]);
//     return;
//   }
//   printf("%d ",q -> arr[0]);
//   q -> arr[0] = q -> arr[q ->size-1];
//   q -> size--;
//   maxheapify(q,0);
//   heapsort(q);
// }
void print(heap *p) {
  if (p->size == 0) {
      printf("Heap is empty\n");
      return;
  }
  printf("Heap elements: ");
  for (int i = 0; i < p->size; i++) {
      printf("%d ", p->arr[i]);
  }
  printf("\n");
}

int main() {
  heap *p = NULL;
  inti(&p, 10); // Initialize the heap with a capacity of 10

  // Example array to build the heap
  int arr[] = {10, 20, 15, 30, 40};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Build the max heap
  buildmaxheap(p, arr, n);
  printf("Heap after building from array:\n");
  print(p);

  // Insert a new element into the heap
  insert(p, 50);
  printf("Heap after inserting 50:\n");
  print(p);

  // Delete the root of the heap
  deleteRoot(p);
  printf("Heap after deleting root:\n");
  print(p);


  // Free the allocated memory
  free(p->arr);
  free(p);

  return 0;
}