#include <stdio.h>

int indianness(){
   unsigned num = 0x01020304;

   unsigned b1,b2,b3,b4;

   b1 = n & 255;
   b4 = n>>24; 

   printf("%x, %x",b1,b4);  

}


int main(){

  indianness();

}
