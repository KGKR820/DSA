#include <stdio.h>
#include <limits.h>
int main(){
int arr[4] = {3,2,4,8};
int k,temp;
for(int i=0;i<4;i++){
    temp = INT_MAX;
    for(int j=i;j<4;j++){
        if(temp > arr[j]){
            temp = arr[j];
             k = j;
        } 
    }
    arr[k] = arr[i];
    arr[i] = temp;
}
for(int i=0;i<4;i++){
    printf("%d ",arr[i]);
}
return 0;
}
// output -> 2 3 4 8 