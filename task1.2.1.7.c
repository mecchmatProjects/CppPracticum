#include <stdio.h>


int rec7b(){ //first positive
   int x0=-99,x1=-99,x2=-99,xn;
   //if(k<=2) return -99;
   int k=3;
   //for(int i=3;i<k;++i){
   while(x2<=0){
     xn = x2 + x1 + x0 + 100;
     x0 = x1;
     x1 = x2;
     x2 = xn;
     k++; 
  }  
  printf("k=%d",k);
  return x2;
}



int rec7c(){  /// index of first positive
   int x0=-99,x1=-99,x2=-99,xn;
   //if(k<=2) return -99;
   int k=3;
   //for(int i=3;i<k;++i){
   while(x2<=0){
     xn = x2 + x0 + 100;
     x0 = x1;
     x1 = x2;
     x2 = xn;
     k++;
  }  
  printf("xn=%d",xn)
  return k;
}

int main(){

int k=9;
  printf("x(%d)=%d, %d \n",k,rec7c(k),rec7b(k));

  scanf("%d",&k);
  printf("x(%d)=%d, %d \n",k,rec7c(k),rec7b(k));
}
