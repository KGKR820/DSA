#include <stdio.h>
void merge(int arr[],int l,int mid,int r){
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i] = arr[i+mid+1];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            i++;
            k++;
        }
        else{
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = b[j];
        j++;
        k++;
    }
}

void divide(int arr[],int l,int r){
    if(l < r){
int mid = (l+r)/2 ;
divide(arr,l,mid);
divide(arr,mid+1,r);
merge(arr,l,mid,r);
   }
}

int main(){
int n;
printf("enter the size of array -> ");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    printf("arr[%d] -> ",i);
    scanf("%d",&arr[i]);
}
divide(arr,0,n-1);
printf("sorted array -> ");
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}
    return 0;
}