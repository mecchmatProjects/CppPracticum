#include <stdio.h>
#include <math.h>

int main(){

  unsigned n;
  printf("n="); 
  scanf("%u",&n);
  printf("%u!=",n);
  for(unsigned i=1;i<n;++i){
    printf("%u*",i);
  }
  printf("%u\n",n);

  printf("%u!=",n);
  for(unsigned i=n;i>1;--i){
    printf("%u*",i);
  }
  printf("1\n");


}
