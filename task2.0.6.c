#include <stdio.h>
#include <math.h>

#define NMAX 100

int input(double mas[]); // input array

double sum(double mas[], int n);

int main(){
   double mas[NMAX];
   int n = input(mas);
   
   double s = sum(mas,n);
   printf("S=%lf",s);
}


int input(double mas[]){

   int n = 0;
   do{
     if(n >= NMAX) break;
     printf("mas[%d]=",n);
     scanf("%lf",&mas[n]);
   }while(fabs(mas[n++])>0.0001);

  return n;
}

double sum(double mas[], int n){
  double s =0.0;

  for(int i=0;i<n;++i){
    s += mas[i];
   }
  return s;
}

