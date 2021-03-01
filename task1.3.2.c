#include <stdio.h>

int main(){
 int n,m;  // 
 unsigned char k;
 printf("k=");
 scanf("%hhu",&k); 

 printf("n=");
 scanf("%d",&n); 

 m = n | (1<<k);   

 printf("m=%d\n",m);
}

