
#include <stdio.h> 

typedef 
struct Money{

  int grn; // grivnas
  unsigned char kop; // kopiiky

}Money;


Money vvod(){

  Money res;   
  int t;
  printf("GRn=");
  scanf(" %i",&res.grn);
  //printf("%i",g);
  //printf("kop=");
  scanf(" %d",&t);
  res.kop = (unsigned char) t;
  return res;
}

int input(Money* x){
  Money res;   
  int t;
  printf("GRn=");
  scanf(" %i",&res.grn);
  //printf("%i",g);
  //printf("kop=");
  scanf(" %d",&t);
  res.kop = (unsigned char) t;
  *x =res;
 return 0;
}


void vyvod(const Money x){
  printf("%i gryven %u kop.",x.grn,x.kop);
}

int main(){

  //struct Money x;
  Money x;
  int g; 
  unsigned char g1;


  //x = vvod();
  input(&x); 

  vyvod(x);
}






