#include <stdio.h>
void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i = l-1;
    int j;
    for(j=l;j<=r;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr,i,j);
        
        }
    }

    swap(arr,i+1,r);
    return i+1;
}
void quicksort(int arr[],int l,int r){
    if (l < r) {
        int pi = partition(arr,l,r);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, r);
    }
}
int main(){
    int n, i;
    printf("enter the size of array -> ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("arr[%d] -> ",i);
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("sorted array -> ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
