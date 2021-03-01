#include <stdio.h>
#include <stdint.h>

int main(){
 unsigned n,m;  // unsigned = 32 bits 
 unsigned b1,b2,b3;

 unsigned M8 = 24;
 unsigned Mask = 0x00FFFF00;

 if(sizeof(n)!=sizeof(uint32_t)){
    printf("Here size of unsigned is not 32 bits!!!");
    M8 =  8 * sizeof(unsigned) - 8; 
    Mask = (1<<M8) - (1<<8);  
 }

 printf("n=");
 scanf("%u",&n); 
 
 printf("n=%u %08x\n",n,n);
 b1 = (n & 255) <<24; // last bits change
 //b1 = (n & 255) <<M8;

 b2 = n>>24; // first 8 bits 
 // b2 = n>>M8;
 b3 = n & 0x00FFFF00;  // b3 = ((n<<8)>>16)<<8;
 // b3 = n & mask;

 m =  b1 | b3 | b2;   

 printf("m=%u %08x\n",m,m);
}
