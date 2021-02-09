#include <stdio.h>

// for C89 compatibility
// instead of scanf("%hhu")
unsigned my_scanf_to_uchar(unsigned char *puchar);

int main(){

 unsigned char n; // 0..255
 printf("n=");
 scanf("%hhu",&n);
 //my_scanf_to_uchar(&n);
 long long unsigned m=1L; // longest number

 for(int i=n; i>=1; i-=2){
   m *= i;
 }
  /*
 int i=n;
 
 while(i>1){
    m *=i;
    i-=2; 
 }*/
 /*
 do{
    m *=i;
    i-=2; 
 }while(i>1);*/

 printf("%hhu!!=%Lu\n",n,m);

}



unsigned my_scanf_to_uchar(unsigned char *puchar){ 
  unsigned retval;
  unsigned int uiTemp;
  retval = scanf("%u", &uiTemp);
  if (retval == 1)   
  {
    if (uiTemp < 256) {
      *puchar = uiTemp;
    }
    else {
      retval = 0; //maybe better something like EINVAL
    }
  }
  return retval; 
}
