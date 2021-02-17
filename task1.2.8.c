//task 1.2.8
#include <stdio.h>
#include <math.h>

double s2(unsigned n){
  double y = 0;
  for(unsigned i=0;i<n;++i){
      y =sqrt(2+y);
  }
 return y;
}


int main(){
  double x,y;
  unsigned n;

  printf("n=");
  scanf("%u",&n);

  y = s2(n);

  printf("y=%lf",y);

}

