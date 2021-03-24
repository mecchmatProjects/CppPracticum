#include <stdio.h>
#include <math.h>


int readFile(const char * fname){
  FILE* fp = fopen(fname,"rb"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }
  int x;
  while(1){

     fread(&x,1,sizeof(int),G); // read 1 double from F
     if(feof(G)) break; 
     printf("x%d=%d, ",i++,x);
  }
  
  fclose(fp);
}

int writeFile(const char* fname){
  FILE* fp = fopen(fname,"wb"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }

  char c;
  int x;
  do{
   printf("Continue? y/n");
   c= getchar();
   if(c=='n') break; 
   printf("x=");
   scanf("%d",&x);
   fwrite(&x,1,sizeof(x),fp); 
  }while(1);
   
  fclose(fp);
}

int isSqr(int x){

   int y = floor(sqrt(x));
   int z=y+1;
   return ((y*y==x)|| (z*z==x));
}

int main(){

  const char* fname = "T2.dat";
  
  FILE* F = fopen(fname,"wb"); // open file binary, for writing
  if(F==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }

  int n;
  printf("n=");
  scanf("%d",&n);
  int x;
  for(int i=0;i<n;i++){
     printf("x=");
     scanf("%d",&x);
     fwrite(&x,1,sizeof(x),F); // write x to file F  
  }
  fclose(F);

   F = fopen(fname,"rb");

  const char* fname2 = "T2_1.dat";
  FILE* G = fopen(fname2,"wb");
   int i=0;
   int k=0;
  while(1){
     if(feof(F)) break; 
     fread(&x,1,sizeof(int),F); // read 1 int from F
     printf("\n xF%d=%d, ",i,x);
     //if(x%2==0){
     if(isSqr(x)){ 
     printf("xG%d=%d, ",i,x);
        fwrite(&x,1,sizeof(x),G); 
     }
     
  }
  fclose(F);
  fclose(G);
  printf("\n");

  G = fopen(fname2,"rb");
  i=0;
  while(1){

     fread(&x,1,sizeof(int),G); // read 1 double from F
     if(feof(G)) break; 
     printf("x%d=%d, ",i++,x);
  }
  fclose(G);
  
}
