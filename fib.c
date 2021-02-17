#include <stdio.h>

int fib(int k){

 int f0=0,f1=1; 
 if(k<=1) return k;
 
 for(int i=1;i<k;i++){
                   // f0,f1,fk  
    fk = f0 + f1; // 0,1,1
    f0 = f1;       //1,1,2 
    f1 = fk;       //1,2,3
 }                 //2,3,5  

  return fk;
}

int fibb_n(int n) { 
  if (n==0) { return 0; } 
  else if(n==1) { return 1; } 
  return fibb_n(n-1) + fibb_n(n-2); 
} 



int main(){

  int k=9;
  printf("F(%d)=%d",k,fib(k));

  scanf("%d",&k);
  printf("F(%d)=%d",k,fib(k));

}
