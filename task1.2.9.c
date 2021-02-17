#include <stdio.h>
#include <math.h>

double func139a(double x, int n){
 double y = 1;
 double power = 1; 
 for(int i=1;i<=n;++i){
    
    y += i * power; //  i*pow(x,i-1);
    power *= x; // x ** i
 }
 
  return y;
}


double func139c(double x, int n){

 double y = 1;
 double power = x; // 1, x, x^2/2!
 for(int i=1;i<=n;++i){
    
    y += power; //  pow(x,i-1)/ (i)!;
    power *= x /(i+1); // x^i/(i)!
 }
 
  return y;
}



double func139b(double x, int n){

 double y = 1;
 double power = 1;
 for(int i=1;i<=n;++i){
   power *=x;
 } 
 for(int i=1;i<=n;++i){
    y += i * power; //  i*pow(x,i-1);
    power *= (1-x)/x;
 }
 
  return y;
}

int main(){

  double x,y;
  unsigned n;

  printf("n=");
  scanf("%u",&n);

  do{ 
    printf("Input x, |x|<1, x=");
    scanf("%lf",&x);
  }while(fabs(x)>=1);

  

  y = func139a(x,n);

  printf("y=%lf\n",y);

  y = func139b(x,n);

  printf("y=%lf\n",y);
  

  y = func139c(x,n);

  printf("y=%lf\n %lf",y, exp(x));
  

}
