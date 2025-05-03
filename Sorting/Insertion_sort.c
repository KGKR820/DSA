#include <stdio.h>
int main(){
int arr[4] = {3,2,8,4};
for(int i=1;i<4;i++){
    int k = arr[i];
    int j = i-1;
    while(j >= 0 && arr[j] > k){
        arr[j+1] = arr[j];
        arr[j] = k;
        j--;
    }
}
for(int i=0;i<4;i++){
    printf("%d ",arr[i]);
}
    return 0;
}
// output -> 2 3 4 8 