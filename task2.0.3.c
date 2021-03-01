#include <stdio.h>
#include <math.h>

#define N 3// 10

int main(){

  double mas[N];

  for(int i=0;i<N;i++){
     printf("mas[%d]=", i);
     scanf("%lf",&mas[i]);
 }

 double sum = 0.0;
 for(int i=0;i<N;i++){
    if(mas[i]>M_E){
      sum += mas[i];
    }
 }

 printf("Sum =%lf", sum);

}

