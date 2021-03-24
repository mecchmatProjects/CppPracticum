#include <stdio.h>
#include <stdlib.h> //malloc, free

double sum_square(const double const* a, int n){

   double s = 0;
   for(int i=0;i<n;++i){
     s += a[i]*a[i];
  }

  return s;
}

int input(double * a, int n){

   for(int i=0;i<n;++i){
     printf("a[%d]=",i);
     scanf("%lf",&a[i]);
  }
  return 0;
}

int main(){

  int n;
  printf("n=");
  scanf("%d",&n);

  double* a = (double*) malloc(n*sizeof(double)); // double(void*)

  input(a,n); 

  double s = sum_square(a,n);
  printf("s=%lf",s); 

  free(a);
}

