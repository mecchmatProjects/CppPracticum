#include <stdio.h>
// task 1.2.1.3 - Koblitz

int fun_kob(int ak){

 if(ak & 1){  // x%2
   return ((ak<<1) + ak + 1)>>1; // 3*x+1
 }
 return ak>>1; // x/2
}


int koblitz2(int ak);


int A = 3;
int B = 1;
int C = 2;

int koblitz(int ak){

 if(ak % C){  // x%2
   return A * ak + B;
 }
 return ak / C; // x/2
}


int main(){

 int a=27;
 a= 871; 
 do{
    a =koblitz(a);
    printf("%d, ", a);
 }while(a>1);

 printf("\n\n\n");
 int num_max = 0;
 int r=0;
 for(int i=2;i<1000;++i){
    a = i;
    int p = 0; 
   while(a>1){
     //printf("%d, ", a);
    a = koblitz(a);
    p++;
   }

  //printf("%d, ",p);

  if(num_max<p){
     num_max=p;
     r=i;
  } 
  
 }

 printf("\n N=%d for %d", num_max, r);

}



int koblitz2(int ak){

 if(ak % C){  // x%2
   return (A * ak + B)%4?(A * ak + B):(A * ak + B+2);
 }
 return ak / C; // x/2
}
