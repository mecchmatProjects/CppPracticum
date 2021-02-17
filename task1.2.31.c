#include <stdio.h>

unsigned gcd(unsigned x, unsigned y){

   if(x>y){
      while(y>0){
          unsigned tmp = x;
          x = y;
          y = tmp % y;
      }   
     return x;
   }

      while(x!=0){
          unsigned tmp = y;
          y = x;
          x = tmp % x;
      }   
     return y;

}

unsigned Eiler(unsigned n){
 
  unsigned res = 1;

  for(int i=2;i<n;++i){
   if(gcd(i,n)==1) res++;
   //printf("%u",gcd(i,n));
 }  

 return res;
}

int main(){

  unsigned a=17;

  printf("Phi(%u)=%u\n",a,Eiler(a));

}
