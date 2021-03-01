#include <stdio.h>

int main(){
 int n,m;  // 0..255  ubyte == uint8_t
 unsigned char k;
 printf("k=");
 scanf("%hhu",&k); 

 printf("n=");
 scanf("%d",&n); 

 m = n & ~(1<<k);   

 printf("m=%d %x\n",m,m);
}

