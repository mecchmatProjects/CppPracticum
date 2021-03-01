#include <stdio.h>


int non_zeros0(unsigned n){
  int res= 0;
  for(int i=1;i<=n;i<<=1)
        if(n & i) res++; //  watch i-th bit form left
    }

  return res;
}


int non_zeros1(unsigned n){
  int res= 0;
  while(n){
        if(n & 1) res++; //  watch i-th bit form right
        n>>=1; // n = n/2
    }

  return res;
}


int non_zeros(unsigned n){
  int res=0;
  while(n){
        res++;
        n = n & (n-1); //  to next nonzero bit value
    }

  return res;
}


int main() {
    unsigned n;
    int i = 0;
    scanf("%u",&n);
    
    printf("nz bits=%d",non_zeros(n));
    return 0;
}
