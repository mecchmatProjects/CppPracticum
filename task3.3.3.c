#include <stdio.h>
#include <stdlib.h>

double * vect(int n){
   double * a = calloc(n,sizeof(double));
   return a;
}

int input(double *a, int n){
   for(int i=0;i<n;++i){
     printf("a[%d]=",i);
     scanf("%lf",&a[i]);
   }
 return 0;
}

double* dif(double* v1,int n1, double* v2,int n2){

   double* res = NULL;
   if(n1==n2){

   res = calloc(n1,sizeof(double));

   for(int i=0;i<n1;++i){
     res[i] = v1[i] - v2[i];
   }
   return res;
  }
  
  return res;  
  
}

void print(double* v, int n){
 printf("\n"); 
 for(int i=0;i<n;++i)
   printf("v[%d]=%lf, \t",i,v[i]);

}

void delete(double* v){
   free(v);
}

int main(){

  int n1,n2;
  printf("n=");
  scanf("%d",&n1);

  double* v1 = vect(n1);
  if(v1==NULL) return -1;
  input(v1,n1);

  printf("n=");
  scanf("%d",&n2);
  double* v2 = vect(n2);
  if(v2==NULL){
   delete(v1); 
   return -2;
 }
  input(v2,n2);

  double * v3;
   //print(v1,n1);
   //print(v2,n2);

  v3 = dif(v1,n1,v2,n2);

  if(v3){
      print(v3,n1);
      free(v3);
  } 
 else{
  printf("n1<>n2 - no difference");
} 

  free(v2);
  free(v1); 
}
