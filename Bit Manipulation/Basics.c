#include <stdio.h>
int main(){
   int a = 5,b=9;
   //and(&)
   // or(|) {No Carry 5 | 9 = 13}
   // xor(^)
   // Left Shift by n bits(<< n{>0 and < Value Bits}) => val*(2^n)
   //Right Shift by n bits(>> n{>0 and < Value Bits}) => val/2^n
   // not(~)
   printf("%d\n%d\n%d\n%d\n%d\n", a & b, a | b, a ^ b, a << 1, a >> 2);
   return 0;
}
