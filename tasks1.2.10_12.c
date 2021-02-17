// tasks 10-12

#include <stdio.h>
#include <float.h>

int main(){

   unsigned n,m;
   printf("m=");
   scanf("%u", &m);
   printf("n=");
   scanf("%u", &n);
 
   unsigned p1=1,p2=1;
   unsigned i1=0,i2=0;

   while(p1<m){
     p1 *= 4;
     i1++;
   }
   i1--; //!!! to make 4^i1 less then m
 
   do{
     p2 *= 2; 
     i2++;
   }while(p2<=n);
   
   printf("max k=%u that 4^%u < m=%u\n",i1,i1,m);
   printf("min r=%u that 2^%u > n=%u\n",i2,i2, n);
  
   double eps=1.0;

   while(eps+1.0!=1.0){
     //printf("%lf",eps);  
     eps /= 2;
   }

   printf("eps=%.20lf, %le  or eps=%.20lf,%le", 2*eps,2*eps, DBL_EPSILON,DBL_EPSILON);
  
}
