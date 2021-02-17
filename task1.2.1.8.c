#include <stdio.h>

double seq_frac_a(double b, unsigned n){
    double res = b;
    for(unsigned i=0;i<n;++i){
        res = b + 1/res;
    }

   return res;
}


double seq_frac_b(double b, unsigned n){
    double res = b;
    for(unsigned i=0;i<n;++i){
        res = b + 1/res;
    }

   return res;
}



int main(){
  unsigned n;
  printf("n=");
  scanf("%u",&n);
  double b;
  printf("b=");
  scanf("%lf",&b);
  printf("b=%lf",seq_frac_a(b,n));

}
