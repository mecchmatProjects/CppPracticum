#include <stdio.h>
#include <math.h>

#define N 5

int max_arr(int mas[], int size){
 
 int max_mas = mas[0];
 
 for(int i=1;i<size;i++){
    if(mas[i]>max_mas){
      max_mas = mas[i];
    }
 }

 return max_mas; 
}


int main(){

  int mas[N];

  for(int i=0;i<N;i++){
     printf("mas[%d]=", i);
     scanf("%d",&mas[i]);
 }


 printf("Max =%d", max_arr(mas,N));

}

