
#include <stdio.h>
#include <float.h> // DBL_EPSILON, DBL_MAX
#include <math.h> //fabs
#include <stdbool.h> // bool type


bool isNearlyZero(double x){
   return (fabs(x)<2*DBL_EPSILON); // return (fabs(x)<0.000001); fabs(x) =|x|
}

bool isNearlyEqual(double x, double y){
   return (fabs(x-y)<2*DBL_EPSILON);

}

double onestep(double x){
 /* if(x>=0) return 1;
  else return 0;*/

 return (x>=0)?1:0;  // Python: 1 if (x>=0) else 0
}


//DBL_MAX
double onestep_derivative(double x){
  if(isNearlyZero(x)) return DBL_MAX; // x==0.- bad double comparison 
  return 0;
}

double ReLu(double x){
   if(x<=0) return 0; // x<=0?0:x;
   return x;
}

double ReLu_derivative(double x){
  if(isNearlyZero(x)) return 0.5; // x==0.- bad double comparison 
  else if (x<0) return 0;  
  else return 1;
}

int main(){

   if(!isNearlyEqual(1,onestep(2))){
     printf("not equal onestep for x=1\n");
  }

   if(!isNearlyEqual(2,ReLu(2))){
     printf("not equal Relu for x=2\n");
  }

   if(!isNearlyEqual(1,ReLu_derivative(2))){
     printf("not equal Relu deriv for x=1\n");
  }


}
