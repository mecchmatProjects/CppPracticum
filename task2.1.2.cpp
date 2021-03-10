/*
Двовимірна матриця 3х3 ініціалізована дійсними числами {{1.0,
2,3,},{4,5,6},{7,8,9}}. Транспонуйте цю матрицю, введіть натуральні
числа I і J та дійсне число A замініть елемент з індексами IJ на
число A (відслідкуйте при цьому коректність індексів). Виведіть
отриману матрицю рядок за рядком 

*/

#include <iostream>

using namespace std;

static const size_t N = 3;

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
           cout<<matr[i][j]<<", ";
       }  
       cout<<endl;
    }

}


void change(double matr[N][N], int n1, int m1){

  for(int i=0;i<N;++i){
       for(int j=0;j<N;++j){
           if(matr[i][j]==n1){
               matr[i][j] = m1;
            }
       }  
    }

}

int mute(double matr[N][N], unsigned i, unsigned j, double a){

     if(i>=N || j>=N) {
        cout<<"wrong indexes"<<i<<","<<j<<"\n";
        return -1;
    }
   
    matr[i][j] = a;
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

    unsigned i, j;
    cout<<"N, M:";
    cin>>i>>j;
   
    double a;
    cout<<"a="; 
    cin>>a;
    
    mute(matr,i,j,a);
    vyvod(matr);
}
