#include <stdio.h>
#include <string.h>
void countDistinct(int arr[], int k, int n) {
    printf("Output: [");

    int freq[20001] = {0}; 
    int distCnt = 0;
    for (int i = 0; i < k; i++) {
        if (freq[arr[i] + 10000] == 0) {
            distCnt++;
        }
        freq[arr[i] + 10000]++;
    }
    printf("%d", distCnt);

    for (int j = k; j < n; j++) {
        if (freq[arr[j - k] + 10000] == 1) {
            distCnt--;
        }
        freq[arr[j - k] + 10000]--;

        if (freq[arr[j] + 10000] == 0) {
            distCnt++;
        }
        freq[arr[j] + 10000]++;

        printf(", %d", distCnt);
    }

    printf("]\n");
}

int main() {
    int n;
printf("Enter the size of the array -> ");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    printf("e%d -> ");
    scanf("%d",&arr[i]);
}
int k;
printf("Enter K -> ");
scanf("%d",&k);
if (k <= 0 || k > n) {
    printf("Invalid value of K");
    return 1;
}
countDistinct(arr,k,n);
    return 0;
}