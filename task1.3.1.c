#include <stdio.h>

int main(){
 unsigned char n;  // 0..255 == ubyte == uint8_t
 unsigned long long m;
 printf("n=");
 scanf("%hhu",&n);   

 m = 1<<n; // 2 ** n  (n<64)  1 = 1<<0 , 1<<1 == (10)== 2  1<<2 =100 = 4
 printf("m=%Lu",m);
}


