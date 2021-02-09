#include <stdio.h>


int main(){

  double y,power,x;
  unsigned n;
  printf("x="); 
  scanf("%lf",&x);
  printf("\n n="); 
  scanf("%u",&n);

  y = 0;
  power = 1; // (x-1)**i
  for(int i=0;i<=n;i++){
     y += power; // y=y+power
     power *= (x-1); // power = power*(x-1) == x-1^i     
  }

  printf("y=%lf",y);
}
