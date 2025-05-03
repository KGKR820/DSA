#include <stdio.h>
int bin(int arr[], int left, int right, int key){
	if(left > right){
		return -1;
	}
	int mid = (left+right)/2;
	if(arr[mid] == key){
		return mid;
	}
	if(arr[left] <= arr[mid]){
	       if(key < arr[mid] && arr[left] <= key){
		       return bin(arr, left, mid-1,key);
	       } else {
		       return bin(arr, mid+1, right, key);
	       }
	}
	else{
		if(arr[mid] < key && arr[right] >= key){
			return bin(arr, mid+1, right, key);
		} else {
			return bin(arr, left, mid-1, key);
		}
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
	int s;
	printf("Search element:");
	scanf("%d", &s);
	printf("%d", bin(arr, 0, n-1, s));
}
// Enter number of elements: -> 8
// arr[0] -> 6
// arr[1] -> 7
// arr[2] -> 8
// arr[3] -> 1
// arr[4] -> 2
// arr[5] -> 3
// arr[6] -> 4
// arr[7] -> 5
// Enter the element to search: -> 3
// Element found at index 5
