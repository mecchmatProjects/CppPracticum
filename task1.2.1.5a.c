#include <stdio.h>

int fib_a(int M){
 int k=0; 
 int f0=0,f1=1,fk; 
 
 for(;f1<M;){  // while(f1<M)
    k++;
                   // f0,f1,fk  
    fk = f0 + f1; // 0,1,1
    f0 = f1;       //1,1,2 
    f1 = fk;       //1,2,3
 }                 //2,3,5  

  return k;
}


int fib_b(int M){

 int f0=0,f1=1,fk; 
 int k=1;
 
 while(f1<M){
    k++;               // f0,f1,fk  
    fk = f0 + f1; // 0,1,1
    f0 = f1;       //1,1,2 
    f1 = fk;       //1,2,3
 }                 //2,3,5  

  return k;
}



int main(){

  int k=19;
  printf("F(%d)<%d, F(%d)>%d \n",fib_a(k),k, fib_b(k),k);

  scanf("%d",&k);
  printf("F(%d)<%d, F(%d)>%d \n",fib_a(k),k, fib_b(k),k);

}
