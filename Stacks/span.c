#include <stdio.h>
void span(int arr[],int len){
   int span[len];
   for(int i=0;i<len;i++){
    int count = 0;
    for(int j=i;j<=0;j--){
       if(arr[j] <= arr[i]){
        count ++;
       }
      else{
        break;
      }
    }
    span[i] = count;
   }
   for(int i=0;i<len;i++){
    printf("%d",span[i]);
   }
}
int main(){
int arr[7] ={2,4,3,7,1,9,6};
span(arr,7);
    return 0;
}
// An inefficient algorithm of finding span with time complexity O(n^2)