/*
1) Двовимірна матриця 3х3 ініціалізована числами
{{1,2,3,},{4,5,6},{7,8,9}}. Транспонуйте цю матрицю, введіть
натуральні числа N і M та замініть елемент, що рівний числу M 

*/

#include <stdio.h>

#define N 3

void transp(int matr[N][N]){

    for(int i=0;i<N;++i){
       for(int j=0;j<i;++j){
            // i,j -> j,i; j,i -> i,j 
           int tmp = matr[i][j];
           matr[i][j] = matr[j][i];
           matr[j][i] = tmp; 
       }  
    }

}

void vyvod(int matr[N][N]){

  for(int i=0;i<N;++i){
       for(int j=0;j<N;++j){
           printf("%d, ",matr[i][j]);
       }  
       printf("\n");
    }

}


void change(int matr[N][N], int n1, int m1){

  for(int i=0;i<N;++i){
       for(int j=0;j<N;++j){
           if(matr[i][j]==n1){
               matr[i][j] = m1;
            }
       }  
    }

}

int main(){

 int matr[N][N]={
                {1,2,3,},
                {4,5,6},
                {7,8,9}
               };

    transp(matr);
    vyvod(matr);

    int n1, m1;
    printf("N, M:");
    scanf("%d",&n1);
    scanf("%d",&m1);

    change(matr,n1,m1);
    vyvod(matr);
   
}
