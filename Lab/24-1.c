#include <stdio.h>
int bin(int arr[], int s, int n) {
    if (n == 0) {
        return -1;
    }
    if (arr[n - 1] == s) {
        return n - 1;
    } else {
        return bin(arr, s, n - 1);
    }
}

int main() {
    int n;
    printf("Enter the size of array -> ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d] -> ", i); 
        scanf("%d", &arr[i]);
    }

    int s;
    printf("Search element -> ");
    scanf("%d", &s);

    int m = bin(arr, s, n);

    if (m == -1) {
        printf("Element not found\n"); 
    } else {
        printf("Index: %d\n", m); 
    }

    return 0;
}
