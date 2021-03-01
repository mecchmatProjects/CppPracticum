#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//b)
double func_b(double x, double eps){
  double a,y;
  a = 1.0; 
  y = a;
  int k=0;
  while(fabs(a)>eps){
     k++;
     a = a * (-x) * k*k / (k+1)/(k+1); // 1, -x/1^2, x^2/3^2, .....
     y += a;
 }

 return y;
}

// g
double func_g(double x, double eps){
  double a,y;
  a = x; 
  y = a;
  int k=0;

  while(fabs(a)>eps){
     k++;
     a = a * (-x*x) / k / (2*k)/(2*k+1); // x, -x**3/2!/3!, x**5/3!/5! , .....
     y += a;
 }

 return y;
}

int main(){

  double x,eps;
  double a,y;
  int k=0;

  do{
    printf("x(x!=0)=");
    scanf("%lf",&x);
  } while(fabs(x)<0.00001);


  do{
    printf("eps(eps>0)=");
    scanf("%lf",&eps);
  } while(eps<0.00001);

// b)
/*
  a = 1.0; 
  y = a;
  while(fabs(a)>eps){
     k++;
     a = a * (-x) * k*k / (k+1)/(k+1); // 1, -x/1^2, x^2/3^2, .....
     y += a;
     
 }
*/

  y =func_g(x,eps);
  printf("y=%lf",y);



}
