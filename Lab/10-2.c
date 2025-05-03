#include <stdio.h>
int par(char *str,int n,int count){
    if(str[n] == '\0') return count;
    if((n%2) == (str[n] - '0')) return par(str,n+1,count+1);
    else return par(str,n+1,count);

}
int main(){
char *str = "101100";
printf("%d",par(str,0,0));

    return 0;
}