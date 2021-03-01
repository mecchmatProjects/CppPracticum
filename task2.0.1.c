#include <stdio.h>

#define N 5

int main(){

  int mas[] = {5,12,3,4,7};

  double a;
  printf("a=");
  scanf("%lf", &a);

  int count = 0;
  for(int i=0;i<N;i++){
     if (mas[i]<a) count++;
 }

 printf("K=%d",count);

}

