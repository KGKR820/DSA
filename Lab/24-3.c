#include <stdio.h>
int peak(int arr[], int left, int right){
	if(left == right){
		return left;
	}
	if(left+1 == right){
		return (arr[left] > arr[right])? left:right;
	}
	int mid = (left+right)/2;
	if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
		return mid;
	}
	if(arr[mid]<arr[mid+1]){
		return peak(arr, mid+1, right);
	}
	else{
		return peak(arr,left,mid-1);
	}
}
int main(){
	int n;
	printf("Enter number of elements: -> ");
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++){
    printf("arr[%d] -> ",i);
		scanf("%d" , &arr[i]);
	}
	printf("index: %d\nvalue: %d",peak(arr,0,n-1),arr[peak(arr,0,n-1)]); 
}