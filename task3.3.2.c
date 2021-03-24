#include <stdio.h>
#include <stdlib.h> //malloc
#include <math.h>

#define N 100

int input(int* a){

  int i=-1;
  do{
     printf("a[%d]=",++i);
     scanf("%d",&a[i]);
  }while(a[i]!=0);

  return i;
}

int num_squares(int* a, int n){
  int m,m1;
  int count =0;
  for(int i=0;i<n;++i){
    if(a[i]<0) continue;
    m = (int)sqrt(a[i]);
    m1 = m+1; 
    if(m*m == a[i]||m1*m1==a[i]){
       count++; 
      //printf("\n %d %d",m,a[i]);
    }
     
    
  }
 return count;
}

int num_cubes(int* a, int n){
  int m,m1;
  int count =0;
  for(int i=0;i<n;++i){
    //if(a[i]<0) continue;
    m = (int)pow(a[i],1.0/3);
    m1 = m+1;
      //printf("\nC %d %d",m,a[i]);
    if(m*m*m == a[i] ||m1*m1*m1==a[i]) {
       count++; 
      //printf("\nCube %d %d",m,a[i]);
    }
  }
 return count;
}

int main(){


  int* a = (int*) malloc(N*sizeof(int));

  int n = input(a); 

  int s = num_squares(a,n);
  int s1 = num_cubes(a,n);
  printf("\n Number of squares=%d, cubes=%d \n",s, s1); 

  free(a);
}
