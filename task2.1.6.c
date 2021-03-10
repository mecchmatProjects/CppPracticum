/*
1) Двовимірна матриця 3х3 ініціалізована числами
{{1,2,3,},{4,5,6},{7,8,9}}. Транспонуйте цю матрицю, введіть
натуральні числа N і M та замініть елемент, що рівний числу M 

*/

#include <stdio.h>

#define N 10
#define M 10


void vyvod(double matr[N][M],unsigned n, unsigned m){

  for(int i=0;i<n;++i){
       for(int j=0;j<m;++j){
           printf("%lf, ",matr[i][j]);
       }  
       printf("\n");
    }

}


int vvod1(double matr[N][M], unsigned n, unsigned m){
    
   for(unsigned i=0;i<n;++i){
       for(unsigned j=0;j<m;++j){
           printf("\na[%u][%u]=",i,j);
           scanf("%lf",&matr[i][j]);
       }  
    }
  return 0;
}

int vvod2(double matr[N][M], unsigned n, unsigned m){
    
   for(unsigned i=0;i<n;++i){
       for(unsigned j=0;j<m;++j){
           scanf(" %lf",&matr[i][j]);
       }  
    }
  return 0;
}

double diff(double matr[N][M], int n, int m, int k){
   double sum = 0; 
   for(unsigned i=0;i<n;++i){
       for(unsigned j=0;j<m;++j){
          if(i-j==k) sum += matr[i][j];
       }  
    }


  return sum;
}

int main(){

 double matr[N][M];

 
    int n, m;
    printf("N, M:");
    scanf("%d",&n);
    scanf("%d",&m);
  
    vvod2(matr,n,m);
    vyvod(matr,n,m);

    int i,j,k;
    printf("k=");
    scanf("%d",&k);
   
   printf("S=%lf",diff(matr,n,m,k));
}
