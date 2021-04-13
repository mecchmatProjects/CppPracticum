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
  while(1){

     int r=fread(&x,sizeof(int),1, fp); // read 1 double from  
    
     if(feof(fp)||r!=1) break;   

     printf("x%d=%d, ",i++,x);
  }
  
  fclose(fp);
  return i;
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
   printf("x=");
   scanf(" %d",&x);
   fwrite(&x,1,sizeof(x),fp); 

   printf("Continue? y/n");
   scanf(" %c",&c);
   if(c=='n') break; 
   
  }while(1);
   
  fclose(fp);
}




int isSqr(int x){

   int y = floor(sqrt(x));
   int z=y+1;
   return ((y*y==x)|| (z*z==x));
}


int writeSqr(const char* fin, const char* fout){

  FILE* fp = fopen(fin,"rb"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fin);
     return -1;
  }

  FILE* f2 = fopen(fout,"wb"); // open file binary, for writing
  if(f2==NULL) {
     fprintf(stderr, "Error open file %s",fout);
     return -1;
  }


  int x;
  int i=0;
  while(1){

     int r=fread(&x,sizeof(int),1, fp); // read 1 double from  
    
     if(feof(fp)||r!=1) break;   

     //printf("x%d=%d, ",i++,x);
     if(isSqr(x)){
         fwrite(&x,sizeof(x),1,f2);
         //TODO: check write
     }
  }
  
  fclose(fp);
  fclose(f2);

}


int main(){

  const char* fname = "1.dat";
  
  writeFile(fname);
 
  readFile(fname);

  printf("\n -----------\n");  

  const char* f2 = "f1.dat";
  writeSqr(fname,f2);
  
  readFile(f2);  
 
}
