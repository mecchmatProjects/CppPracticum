#include <stdio.h>

#include <stdlib.h>

#define N 100

int createDoubleFile(const char* fname, double * mas, int n){
    FILE * fp;
    fp = fopen(fname, "wb");// w - for writing, b- binary
    if(fp==NULL) {
        fprintf(stderr, "Error creating file %s", fname);
        return -1;
    }
    
    int res = fwrite(mas,sizeof(double),n,fp); 
    /*
       1 arg - pointer to data
       2 arg - number of data blocks
       3 arg - size of data block
       4 arg - File pointer 
    */
    
    fclose(fp);
    return res; 
}

int readDoubleFile(const char* fname){
    FILE * fp;
    fp = fopen(fname, "rb");// r - for reading, b- binary
    if(fp==NULL) {
        fprintf(stderr, "Error reading file %s", fname);
        return -1;
    }
   
   double x;
   int k=0;
   while(!feof(fp)){
      int r=fread(&x,sizeof(double),1,fp);
      if(r==0) break;
      printf("\nresult of reading %d, x[%d]=%lf,  ", r, k++, x);      
   }

   fclose(fp);

   return k;
}


int main(){
  
   double mas[N];
   int n;
   printf("n=");
   scanf("%d",&n);
   for(int i=0;i<n;++i){
    printf("mas[%d]=",i);
    scanf("%lf",&mas[i]);
  }
  
  char fname[20] ="1.dat";  
  int r = createDoubleFile(fname, mas, n);
  printf("write %d doubles",r);

  r = readDoubleFile(fname);
  printf("\nread %d doubles",r);
}
