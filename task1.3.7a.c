#include <stdio.h>
#include <float.h> // DBL_EPSILON, DBL_MAX
#include <math.h> //fabs
#include <stdbool.h> // bool type


bool isNearlyZero(double x){
   return (fabs(x)<2*DBL_EPSILON); // return (fabs(x)<0.000001); fabs(x) =|x|
}

bool isNearlyEqual(double x, double y){
   return (fabs(x-y)< DBL_EPSILON * fabs(x));

}


int printSquareEquation(double a, double b, double c){
    if(isNearlyZero(a)){ // a==0
      if(isNearlyZero(b)){ // b==0
        if(isNearlyZero(c)){   // c==0
           printf("Infinity of solutions\n"); 
           return -1; 
        }
        else{
           printf("No solutions\n");
           return 0;
        }
      }
      else{
         double x = -c/b;
         printf("x=%lf\n",x); 
         return 1;
      }
   }
   else{ //a!=0
      double d = b*b - 4*a*c; 
      if(isNearlyZero(d)){
         double x = -b/(2*a);
         printf("x1=x2=%lf\n",x); 
         return 1; 
      }
      else if(d>0){
         double x1 = (-b - sqrt(d))/2/a;
         double x2 = (-b + sqrt(d))/2/a;
         printf("x1=%lf, x2 =%lf\n",x1,x2); 
         return 2;
      }
     printf("no real solutions\n");  
   }
  return 0;
}

int main(){
  
   printf("%d\n", printSquareEquation(0,0,0));
   printf("%d\n", printSquareEquation(0,0,3));
   printf("%d\n", printSquareEquation(0,8,2));

   printf("%d\n", printSquareEquation(2,4,2));
   printf("%d\n", printSquareEquation(2,-6,4));
   printf("%d\n", printSquareEquation(2,6,14));

   double a,b,c;
   printf("a=");
   scanf("%lf",&a);
   printf("b=");
   scanf("%lf",&b);
   printf("c=");
   scanf("%lf",&c);
 
   printSquareEquation(a,b,c);
}
