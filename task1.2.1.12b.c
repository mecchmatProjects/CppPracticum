#include <stdio.h>

int main(){

 int n;
 double u,v;
 double a1,b1,ak,bk;
 printf("n="); 
 scanf("%d",&n);
  printf("a,b"); 
 scanf("%lf",&u);
 scanf("%lf", &v);

 a1 = u; b1 = v;
 double fct = 2.0; //2! 
 double s = (a1*b1)/fct;
 printf("S=%lf",s);
 for(int i=2;i<=n;i++){
    
     ak = 2 * b1 + a1;
     bk = 2 * a1 * a1 + b1;
     a1 = ak;
     b1 = bk;
     fct *= i;
     s += ak*bk/fct;
  printf("S=%lf %lf %lf\n",s,ak,bk);
 }

  printf("S=%lf",s);


}
