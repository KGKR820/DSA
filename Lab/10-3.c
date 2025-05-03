#include <stdio.h>
void insert(int *arr,int n){
    int j=0;
    for(int i=1;i<n;i++){
        int key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int n;
    printf("SIZE OF ARRAY:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("%d ELEMENT:",i+1);
        scanf("%d",&arr[i]);
    }
    insert(arr,n);
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

}