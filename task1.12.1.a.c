#include <stdio.h>


int main(){

  int ak,bk,a0,b0,a1,b1;

  b0=0;b1=1;
  a0=0,a1=1;

  double s=0;
  int k;  
  scanf("%d",&k);
  s = 2/(a1+b1);
  double power = 2.0; 
  for(int i=2;i<=k;++i){
    bk = a1+ a0;
    ak = a1/i + a0*bk;

    a0=a1;a1=ak;
    b0=b1;b1=bk;
    
    power *=2; 
    s += power /(ak+bk); 

  }


  printf("S=%lf",s);

}
