#include <stdio.h>
#include <math.h>


int readFile(const char * fname){
  FILE* fp = fopen(fname,"rb"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }
  int x;
  int i=0;
  while(!feof(fp)){

     fread(&x,1,sizeof(int),fp); // read 1 double from  
     if(feof(fp)) break;   
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

  const char* fname = "1.dat";
  
  writeFile(fname);
 
  readFile(fname);  
 
}
