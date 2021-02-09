
#include <stdio.h>


int main(){

  double y,power,x;
  unsigned n;
  printf("x="); 
  scanf("%lf",&x);
  printf("\n n="); 
  scanf("%u",&n);
  y = 1;
  power = 1;
  //a
  for(int i=0; i<n;i++){
    power *= x; // power = power* x ---  x^i
    y += power; // y=y+pow(x,i);
  }
  printf("y=%lf",y);

  // b
  power = x;
  y = 1+x;
  for(int i=1; i<n;i++){
    power *= power; // power = power**2 ---  x^i
    y += power; // y=y+pow(x,i);
  }

  //c
  power = x;
  y = 1+x;
  for(int i=1; i<n;i++){
    power *= power*power; // power = power* x ---  x^i
    y += power; // y=y+pow(x,i);
  }
  printf("y=%lf",y);

  // 
 power = x;
 double pow2=x;
 y = 1;
  for(int i=1; i<n;i++){
    pow2 *=x*x;
    power *= pow2; // power = power* x ---  x^i*i
    y += power; // y=y+pow(x,i);
  }
  printf("y=%lf",y);

}

