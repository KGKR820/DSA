#include <stdio.h>
#include <stdlib.h>
int merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int count = 0;
    int leftArr[n1], rightArr[n2];
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
            count = count + (n1 - i); 
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    return count;
}
int mergeSort(int arr[], int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count = count + mergeSort(arr, left, mid);
        count = count + mergeSort(arr, mid + 1, right);
        count = count + merge(arr, left, mid, right);
    }
    return count;
}

int main() {
    int n;
    printf("Enter the size of array -> ");
    scanf("%d",&n);
    int arr[n];
  for(int i = 0; i < n; i++) {
    printf("arr[%d] -> ",i);
    scanf("%d", &arr[i]);
  }
    int count = mergeSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nNumber of inversions: %d\n", count);
    return 0;
}