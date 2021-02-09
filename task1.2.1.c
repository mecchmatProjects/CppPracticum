#include <stdio.h>
#include <math.h>

int main(){

  double y,x;
  unsigned n;
  printf("x="); 
  scanf("%lf",&x);
  printf("\n n="); 
  scanf("%u",&n);
  y=x;
  for(int i=0;i<n;++i){
    y=sin(y);
  }
  
  printf("y=%lf",y);


}
