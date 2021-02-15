#include <stdio.h>
#include <math.h>

int main(){

  unsigned char n;
  printf("n="); 
  scanf("%hhu",&n);

  printf("%hhu!=",n); // n!=
  for(unsigned char i=1;i<n;++i){
    printf("%hhu*",i); // i*
  }
  printf("%hhu\n",n); 

  printf("------\n");

  printf("%hhu!=",n); //n!=
  for(unsigned char i=n;i>1;--i){
    printf("%hhu*",i); // i*
  }
  printf("1\n"); //1


  printf("------\n");

  printf("%hhu!=",n); //n!=
  unsigned char i=1;

  while(i<n){
    printf("%hhu*",i++);
  }  

  printf("%hhu\n",n); //1


}
