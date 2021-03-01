#include <stdio.h>
#include <stdint.h>

int endianness(){
   uint32_t num = 0x01020304;

   uint32_t b1,b2,b3,b4;

   b1 = num & 255;
   
   b2 = (num>>8) & 255;
   b3 = (num>>16) & 255;
  
   b4 = num>>24; 
   printf("%x, %x ,%x, %x\n",b1,b2,b3,b4);  

   if(b1==4 && b4==1){ 
        if(b2==3 && b3==2){
             printf("little-endian");
             return 1;
        }
                 
        else if (b2==2 && b3==3){
             printf("middle-endian");
             return 2;
       }
       printf("unknown type");
       return -1;
   }

   if(b1==1 && b4==4 && b2==3 && b3==2) {
     printf("big-endian");
     return 3;
   }

   printf("unknown type");
   return -1;
}


int main(){

  endianness();

}
