#include <stdio.h>
int main(){
    int n;
    printf("Enter the size of array -> ");
    scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    printf("arr[%d] -> ",i);
    scanf("%d",&arr[i]);
}
int k;
printf("Enter the no of turns to rotate -> ");
scanf("%d",&k);

    return 0;
}