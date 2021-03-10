/*
1) Двовимірна матриця 3х3 ініціалізована числами
{{1,2,3,},{4,5,6},{7,8,9}}. Транспонуйте цю матрицю, введіть
натуральні числа N і M та замініть елемент, що рівний числу M 

*/

#include <stdio.h>

#define N 10
#define M 10


void vyvod(int matr[N][M],unsigned n, unsigned m){

  for(int i=0;i<n;++i){
       for(int j=0;j<m;++j){
           printf("%d, ",matr[i][j]);
       }  
       printf("\n");
    }

}


int vvod1(int matr[N][M], unsigned n, unsigned m){
    
   for(unsigned i=0;i<n;++i){
       for(unsigned j=0;j<m;++j){
           printf("\na[%u][%u]=",i,j);
           scanf("%d",&matr[i][j]);
       }  
    }

}

int vvod2(int matr[N][M], unsigned n, unsigned m){
    
   for(unsigned i=0;i<n;++i){
       for(unsigned j=0;j<m;++j){
           scanf(" %d",&matr[i][j]);
       }  
    }

}

int main(){

 int matr[N][M];
 int matr2[N][M];

 
    int n, m;
    printf("N, M:");
    scanf("%d",&n);
    scanf("%d",&m);
  
    vvod1(matr,n,m);
    vyvod(matr,n,m);

    vvod2(matr2,n,m);
    vyvod(matr2,n,m);
   
}
