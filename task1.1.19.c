#include <stdio.h>
#include <float.h> // DBL_EPSILON, DBL_MAX
#include <math.h> //fabs
#include <stdbool.h> // bool type


bool isNearlyZero(double x){
   return fabs(x)<0.000001; //2*DBL_EPSILON); //  fabs(x) =|x|
}

bool isNearlyEqual(double x, double y){
   return (fabs(x-y)<= DBL_EPSILON* 2*(fabs(x) + fabs(y)));
}


double onestep(double x) {
    if(x >= 0) return 1;
    return 0;  
   //return (x>=0)?1:0;
   
}

double onestep_derivative(double x) {
    if(isNearlyZero(x)) return DBL_MAX; // x==0
    return 0; 
}



double ReLu(double x) {   
   return (x>=0)?x:0;
   
}

double ReLu_derivative(double x) {
    if(isNearlyZero(x)) return 0.5; // x==0
    else if(x<0){
        return 0;
    }
    return 1; 
}


int main(){

  if(isNearlyZero(onestep(-2)-0)){
   printf("ok1");
  }

  if(isNearlyEqual(onestep_derivative(-2),0)){
   printf("ok2");
  }

   if(isNearlyZero(ReLu(-2)-0)){
   printf("ok3");
   }

  if(isNearlyEqual(ReLu_derivative(-2),0)){
   printf("ok4");
  }


}
