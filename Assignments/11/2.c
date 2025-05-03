#include <stdio.h>
#include <string.h>
int find(char *s){
   int count[256] = {0};
   int n = strlen(s);
   for(int i=0;i<n;i++){
    count[(int)s[i]]++;
   }
   for(int i=0;i<n;i++){
    if(count[(int)s[i]] == 1){
       return i;
    }
   }
   return -1;
}
int main(){
 char s[90];
printf("Enter The Sentence -> ");
gets(s);
int p = find(s);
printf("%d",p);
    return 0;
}