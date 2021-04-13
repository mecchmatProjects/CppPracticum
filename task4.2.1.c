#include <stdio.h>

#include <stdlib.h>
#include <math.h>

#include <errno.h>
#define N 100

int createDoubleFile(const char* fname){
    FILE * fp;
    fp = fopen(fname, "wb");// w - for writing, b- binary
    if(fp==NULL) {
        fprintf(stderr, "Error creating file %s", fname);
        return -1;
    }
  
    int n;
    printf("n=");
    scanf("%d",&n);  
    double x;
    for(int i=0;i<n;++i){
      printf("x_%d=",i);
      scanf("%lf",&x);
      // to be carefull
      if(fwrite(&x,sizeof(x),1,fp)!=1){
        fprintf(stderr,"error writing");
        fclose(fp);
        return i;
       }
    }
    
    fclose(fp);
    return n; 
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
 
//C11 and MS secure
/* // https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/fopen-s-wfopen-s?view=msvc-160
int readDoubleFile2(const char* fname){
FILE *fp;
int err; // errno_t is NOT supported in gcc!!!

if ((err = fopen_s(&fp, fname, "r")) != 0) {
    // File could not be opened. filepoint was set to NULL
    // error code is returned in err.
    // error message can be retrieved with strerror(err);
    fprintf(stderr, "cannot open file '%s': %s\n",
            fname, strerror(err));
    // If your environment insists on using so called secure
    // functions, use this instead:
    char buf[strerrorlen_s(err) + 1];
    strerror_s(buf, sizeof buf, err);
    fprintf_s(stderr, "cannot open file '%s': %s\n",
              fname, buf);
} else {
    // File was opened, filepoint can be used to read the stream.
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

}
*/

int createG(const char* f1, const char*f2, double a){

    FILE * fp;
    fp = fopen(f1, "rb");// r - for reading, b- binary
    if(fp==NULL) {
        fprintf(stderr, "Error reading file %s", f1);
        return -1;
    }
  
   FILE * gp;
    gp = fopen(f2, "wb");
    if(fp==NULL) {result of reading 1, x[0]=4.000000,  
result of reading 1, x[1]=4.000000,  
read 2 doubles
        fprintf(stderr, "Error write file %s", f2);
        return -1;
    }
  
   
   double x;
   int k=0;
   while(!feof(fp)){
      int r=fread(&x,sizeof(double),1,fp);
      if(r!=1) break;
      //printf("\nresult of reading %d, x[%d]=%lf,  ", r, k++, x);     
      if(fabs(x)<a){
          r=fwrite(&x,sizeof(double),1,gp);
          if(r!=1) {
             fprintf(stderr, "Error write file %s", f2);
         }
      }
   }

   fclose(fp);
   fclose(gp);
   

}


int midifyF(const char* f1, double a){

    FILE * fp;
    fp = fopen(f1, "rb");// r - for reading, b- binary
    if(fp==NULL) {
        fprintf(stderr, "Error reading file %s", f1);
        return -1;
    }
  
   FILE * gp;
    gp = fopen("tmp.dat", "wb");// r - for reading, b- binary
    if(fp==NULL) {
        fprintf(stderr, "Error write file %s","tmp");
        return -1;
    }
  
   
   double x;
   int k=0;
   while(!feof(fp)){
      int r=fread(&x,sizeof(double),1,fp);
      if(r!=1) break;
      //printf("\nresult of reading %d, x[%d]=%lf,  ", r, k++, x);     
      if(fabs(x)>=a){
          r=fwrite(&x,sizeof(double),1,gp);
          if(r!=1) {
             fprintf(stderr, "Error write file %s", "tmp");
         }
      }
   }

   //fclose(fp);
   //fclose(gp);
   freopen(f1,"wb",fp);
   freopen("tmp.dat","rb",gp);
   while(!feof(gp)){
      int r=fread(&x,sizeof(double),1,gp);
      if(r!=1) break;
      //printf("\nresult of reading %d, x[%d]=%lf,  ", r, k++, x);     
      if(fabs(x)>=a){
          r=fwrite(&x,sizeof(double),1,fp);
          if(r!=1) {
             fprintf(stderr, "Error write file %s", f1);
         }
      }
   }
 fclose(fp);
 fclose(gp);

 remove("tmp.dat");
}


int midifyF1(const char* f1, double a){

    FILE * fp;
    fp = fopen(f1, "rb");// r - for reading, b- binary
    if(fp==NULL) {
        fprintf(stderr, "Error reading file %s", f1);
        return -1;
    }
  
   FILE * gp;
    gp = fopen("tmp.dat", "wb");// r - for reading, b- binary
    if(fp==NULL) {
        fprintf(stderr, "Error write file %s","tmp");
        return -1;
    }
  
   
   double x;
   int k=0;
   while(!feof(fp)){
      int r=fread(&x,sizeof(double),1,fp);
      if(r!=1) break;
      //printf("\nresult of reading %d, x[%d]=%lf,  ", r, k++, x);     
      if(fabs(x)>=a){
          r=fwrite(&x,sizeof(double),1,gp);
          if(r!=1) {
             fprintf(stderr, "Error write file %s", "tmp");
         }
      }
   }

   fclose(fp);
   fclose(gp);
    
   remove(f1);
   rename("tmp.dat",f1);
}


int midifyF2(const char* f1, double a){

    FILE * fp;
    fp = fopen(f1, "rb");// r - for reading, b- binary
    if(fp==NULL) {
        fprintf(stderr, "Error reading file %s", f1);
        return -1;
    }
   
   
   //FILE* tmp = tmpfile(); // tmpfile_s()
    char* tmp_name = tmpnam(NULL);
    FILE* tmp = fopen(tmp_name, "wb");
    if (tmp == NULL)
    {
        puts("Unable to create temp file");
        return 0;
    }
  
   
   double x;
   int k=0;
   while(!feof(fp)){
      int r=fread(&x,sizeof(double),1,fp);
      if(r!=1) break;
      //printf("\nresult of reading %d, x[%d]=%lf,  ", r, k++, x);     
      if(fabs(x)>=a){
          r=fwrite(&x,sizeof(double),1,tmp);
          if(r!=1) {
             fprintf(stderr, "Error write file %s", tmp_name);
         }
      }
   }
   
   fclose(fp);
   fclose(tmp); 
   remove(f1);  
   rename(tmp_name,f1); //  tmpnam_s(NULL)
     
}


int main(){
  
  char fname[20] ="F2.dat";  
  int r = createDoubleFile(fname);
  printf("write %d doubles",r);

  r = readDoubleFile(fname);
  printf("\nread %d doubles",r);

  double a;
  printf("\n a=");
  scanf("%lf",&a);

  char gname[20]="G2.dat";
  
  createG(fname,gname,a);
   
  r = readDoubleFile(gname);
  printf("\nread %d doubles",r);
  
  midifyF2(fname,a);
  r = readDoubleFile(fname);
  printf("\nread %d doubles",r);

}
