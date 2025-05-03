#include <stdio.h>
#include <limits.h>
int main(){
int arr[4] = {3,2,4,8};
for(int i=1;i<4;i++){
    for(int j=0;j<4-i;j++){
        if(arr[j] > arr[j+1]){
            int k = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = k;
        }
    }
}
for(int i=0;i<4;i++){
    printf("%d ",arr[i]);
}
return 0;
}
// output -> 2 3 4 8 