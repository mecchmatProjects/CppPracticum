#include <stdio.h>
#include <stdlib.h>

double * matrix(int n){
   double * a = calloc(n*n,sizeof(double));
   if(a==NULL) return NULL;
   int k=0;
   for(int i=0;i<n;++i){
        
       for(int j=0;j<n;++j){
        printf("a[%d,%d]=",i,j);
        scanf("%lf",&a[k++]);
     }
      
   }
   return a;
}

void matr_free(double * matr, int n){
   
   free(matr);
}

double* mult(double* v1,int n1, double* v2,int n2){

   double* res=NULL;
   if(n1==n2){

     res =calloc(n1*n2,sizeof(double));
    
   for(int i=0;i<n1;++i){
	   for(int j=0;j<n1;++j){
	   	for(int k=0;k<n1;++k){
	               res[i*n1 + k] += v1[i*n1 +j]*v2[j*n2+k];
		} 
	   }
   }
   return res;
  }

  return res;  
 
}

void print(double* v, int n){
 printf("\n"); 
 int k=0;
 for(int i=0;i<n;++i){
  for(int j=0;j<n;++j){
     printf("%lf \t",v[k++]);
   }
   printf("\n");
  }
}

int main(){

  int n1,n2;
  printf("n=");
  scanf("%d",&n1);

  double* v1 = matrix(n1);
  if(!v1) {
     printf("Matrix1 not allocated");
     return -1;
  }

  printf("n=");
  scanf("%d",&n2);
  double* v2 = matrix(n2);

  if(!v2) {
     printf("Matrix1 not allocated");
     matr_free(v1);
     return -1;
  }

  double* v3;
  // print(v1,n1);
  // print(v2,n2);
 
  v3 = mult(v1,n1,v2,n2);

  if(v3){
      print(v3,n1);
      matr_free(v3,n1);
   }
  else{
    printf("Check dimensions");
  } 
  matr_free(v2,n2);
  matr_free(v1,n1); 
}
