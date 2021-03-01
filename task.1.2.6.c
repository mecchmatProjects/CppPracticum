#include <stdio.h>

int main(){
 unsigned n,m;  // 0..255  ubyte == uint8_t
 unsigned b1,b2,b3;

 printf("n=");
 scanf("%u",&n); 
 
 b1 = (n & 255) <<24;
 b2 = n>>24;

 b3 = n & 0x00FFFF00;

 m =  b1 | b3 | b2;   

 printf("m=%u %x\n",m,m);
}
