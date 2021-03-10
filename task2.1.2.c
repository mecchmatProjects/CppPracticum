/*
Двовимірна матриця 3х3 ініціалізована дійсними числами {{1.0,
2,3,},{4,5,6},{7,8,9}}. Транспонуйте цю матрицю, введіть натуральні
числа I і J та дійсне число A замініть елемент з індексами IJ на
число A (відслідкуйте при цьому коректність індексів). Виведіть
отриману матрицю рядок за рядком 

*/

#include <stdio.h>

#define N 3

void transp(double matr[N][N]){

    for(int i=0;i<N;++i){
       for(int j=0;j<i;++j){
            // i,j -> j,i; j,i -> i,j 
           double tmp = matr[i][j];
           matr[i][j] = matr[j][i];
           matr[j][i] = tmp; 
       }  
    }

}

void vyvod(double matr[N][N]){

  for(int i=0;i<N;++i){
       for(int j=0;j<N;++j){
           printf("%lf, ",matr[i][j]);
       }  
       printf("\n");
    }

}


int mute(double matr[N][N], unsigned n1, unsigned m1, double a){

    if (n1>=N && m1>=N) {
        printf("Indexes wrong\n");
        return -1;
    }

   matr[n1][m1] = a;
   return 0;
}

int main(){

 double matr[N][N]={
                {1,2,3,},
                {4,5,6},
                {7,8,9}
               };

    transp(matr);
    vyvod(matr);

    unsigned n1, m1;
    printf("I, J:");
    scanf("%u",&n1);
    scanf("%u",&m1);

    double a;
    printf("a=");
    scanf("%lf",&a);
 
 
    mute(matr,n1,m1,a);
    vyvod(matr);
   
}
