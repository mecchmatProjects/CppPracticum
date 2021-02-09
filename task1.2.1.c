#include <stdio.h>
#include <math.h> // sin

int main(){

  double y,x;
  unsigned n;
  printf(" x="); 
  scanf("%lf",&x);
  printf("\n n="); 
  scanf("%u",&n);
  
  y=x;
  /* for(unsigned i=0;i<n;++i){
    y=sin(y);
  }*/
  int i=1;
  while(i<=n){
    y =sin(y);
    i++;
  }
  
  printf("y=%lf  == %lf",y, sin(sin(sin(1.0))));
}
