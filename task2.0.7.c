#include <stdio.h>
//#include <math.h>

#define N 10

int input(double mas[], int size); 
void output(const double mas[], int size); 
int scal_sum(const double mas1[], const double mas2[], double mas3[], int size); 
double scal_mult(const double mas1[], const double mas2[], int size); 

int main(){

  double mas1[N];
  double mas2[N];
  double mas3[N];

  unsigned n;
  double dob;

  do{
    printf("N=");
    scanf("%u",&n);
  }while(n==0 || n>10);
  

  input(mas1,n);
  input(mas2,n);
 
  dob = scal_mult(mas1, mas2, n);

  scal_sum(mas1, mas2, mas3, n);

  printf("Dobutok =%lf", dob);

  output(mas3,n);
}



int input(double mas[], int size){
 
  for(int i=0;i<size;i++){
     printf("mas[%d]=", i);
     scanf("%lf",&mas[i]);
 }

 return size; 
}

void output(const double mas[], int size){
 
  for(int i=0;i<size;i++){
     printf("\n mas[%d]= %lf", i, mas[i]);
 }
}


int scal_sum(const double mas1[], const double mas2[], double mas3[], int size){
 
   for(int i=0;i<size;i++){
      mas3[i] = mas1[i] + mas2[i];
   }

  return 0;
}

double scal_mult(const double mas1[], const double mas2[], int size){
 
   double res = 0; 
   for(int i=0;i<size;i++){
      res += mas1[i]*mas2[i];
   }

  return res;
}


