#include <stdio.h>
int count(int n) {
    if (n == 0) {
        return 0;
    }
    return (n & 1) + count(n >> 1);
}
int main(){
    int n;
    printf("Enter a Number -> ");
    scanf("%d",&n);
    printf("%d",count(n));
    return 0;
}