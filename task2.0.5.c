#include <stdio.h>

//using namespace std;

#define N 5
//static const size_t N = 5; 

int printOdds(unsigned mas[], size_t size){
 
 unsigned  sum1=0,sum2=0;
 
 for(size_t i=0;i<size;i++){
    if(mas[i]%2){
       sum2 += mas[i];
     }
    else{
      sum1 +=mas[i];
   }
 }

 printf("Sum of odds - %u sum of evens - %u",sum1,sum2);
 return 0; 
}


int main(){

  unsigned mas[N];

  for(size_t i=0;i<N;i++){
     printf("mas[%u]=");
     scanf("%u",&mas[i]);
     
 }


 printOdds(mas,N);

}

