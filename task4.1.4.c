
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

/*
У файлі компоненти -- структури вигляду (coef, deg, num ) -- 
дійсний коефіцієнт, ступінь члену полінома та номер поліному. 
Таким чином в файлі записано декілька поліномів (номер поліному встановлює
до якого поліному належить цей член).
Визначити підпрограми для
  виконання наступних дій над поліномом:

введення полінома та запис (додавання) його в файл; 

друк полінома з файлу за номером на консоль у звичному вигляді поліному від $x$;

обчислення похідної від полінома за файлом та номером;

додавання поліному у файл заданий іменем;

видалення поліному за даним номером;

заміна коефіцієнту заданого ступенем та номером поліному;

заміна коефіцієнту заданого номером структури(компоненти) у файлі.
*/

typedef struct{
  double coef;
  unsigned deg;
  unsigned num;
} Poly_Coef; 


int input(Poly_Coef* r){
  printf("n=");
  scanf("%u",&r->num);

  printf("deg=");
  scanf(" %d",&r->deg);

  printf("coef=");
  scanf(" %lf",&r->coef);
  return 0;
}

void printCoef(const Poly_Coef r){
   printf("%lf*x^%u",r.coef,r.deg);
}


int inputPoly(const char* fname){

  FILE *f1 = fopen(fname,"a+b");

  if(f1==NULL){
     printf("error file %s",fname);
     return -1;
  }
  unsigned m;
  printf("number=");
  scanf("%u",&m);  

  unsigned n;
  double a;
  printf("Power n=");
  scanf("%u",&n);
  
  Poly_Coef coef;
  for(unsigned i=0;i<n;i++){
    printf("a[%d]=",i);
    scanf("%lf",&a);

    coef.num = m;
    coef.coef = a;
    coef.deg = i;  
    fwrite(&coef,sizeof(coef),1,f1);
 }

 fclose(f1); 

}


int writePolyToFile(const char* fname){

  remove(fname);
 
  int n;
  printf("Number of Polinomes:");
  scanf("%d",&n);
 
  for(int i=0;i<n;++i){
     inputPoly(fname);
  }
  return 0;
}


int readFile(const char * fname){
  FILE* fp = fopen(fname,"rb"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }
  Poly_Coef x;
  while(!feof(fp)){

     int res = fread(&x,sizeof(x), 1, fp); // read 1 struct from F
     
     if(res<1){ printf("EOF %d\n",res); break;}
     printCoef(x);
  }
  
  fclose(fp);
}

int readPoly(const char * fname, unsigned num){
 FILE* fp = fopen(fname,"rb"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }
  Poly_Coef x;
  int k=-1;
  while(!feof(fp)){

     int res = fread(&x,sizeof(x), 1, fp); // read 1 struct from F
     
     if(res<1){ 
       //printf("EOF %d\n",res); 
       break;
     }

     if(x.num == num){
         if(k==0) printCoef(x);
         else{
            printf("+");
            printCoef(x);
         }
         k++;
     }

  }
  
  fclose(fp);

  return k;
}

int getPoly(const char * fname, unsigned num, double* poly,unsigned pwr){

  FILE* fp = fopen(fname,"rb"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }
  Poly_Coef x;
  int k=-1;
  while(!feof(fp)){

     int res = fread(&x,sizeof(x), 1, fp); // read 1 struct from F
     
     if(res<1){ 
      // printf("EOF %d\n",res); 
       break;
      }

     if(x.num == num){
         if(x.deg<pwr){
             poly[x.deg]=x.coef;
             if(k<x.deg){
               k=x.deg;
             }  
         }
         else{
           printf("degree %u> power %u", x.deg, pwr);
        }
     }

  }
  
  fclose(fp);

  return k;

}

int safeGetPoly(const char * fname, unsigned num, double** pol){
  FILE* fp = fopen(fname,"rb"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }
  Poly_Coef x;
  int k=-1;
  while(!feof(fp)){

     int res = fread(&x,sizeof(x), 1, fp); // read 1 struct from F
     
     if(res<1){ 
      // printf("EOF %d\n",res); 
       break;
      }

     if(x.num == num){
             if(k<x.deg){
               k=x.deg;
             }  
         
     }

  }

  if(k==-1) return 0;
    
  //fclose(fp);  
  double *p= (double*) calloc(k+1,sizeof(*p));

  freopen(fname,"rb",fp);
   while(!feof(fp)){
     int res = fread(&x, sizeof(x), 1, fp); // read 1 struct from F    
     if(res<1){ 
      // printf("EOF %d\n",res); 
       break;
      }

     if(x.num == num){
         p[x.deg] = x.coef;
     }

  }
  
  fclose(fp);

  *pol = p;
  return k;  
}


void printPoly(const double * a, unsigned pwr){

  printf("%lf*x^%u",a[pwr-1],pwr-1);
  for(int i=pwr-2;i>=0;i--){
      if(fabs(a[i])<0.001) continue;
      if(a[i]<0){
         printf("%lf*x^%u",a[i],i);
      }
      else{
         printf("+%lf*x^%u",a[i],i);
      }
  }

}

// в)
void printDerivPoly(const double * a, unsigned pwr){
   
}

// г)
int addPoly(const char* fname, const double * a, unsigned pwr,int num){
   
}

// д)
int deletePoly(const char* fname, unsigned num){
   
}


// e)
int replacePoly(const char* fname, unsigned num, unsigned deg, double coef){

}

// ä)
int replaceStruct(const char* fname, unsigned n, const Poly_Coef r){
    
  FILE* fp = fopen(fname,"ab"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }
  
  fseek(fp,n,0);

  fwrite(&r,sizeof(r),1,fp);
  
  fclose(fp);
}

#define MAX_POLY_DEG 10

int main(){
  char* f = "poly.dat";

  writePolyToFile(f);

 readFile(f);
 int n=1;
 printf("Number of polynome to read:");
 scanf("%d",&n);
 
 int res = readPoly(f,n);
 if(res==0){
    printf("\nNo polynome %d found",n);
 }
 
 double p[MAX_POLY_DEG]={0,};
 int m = getPoly(f,2,p,5);
 printPoly(p,m);

 /*
 double* q;
 m = safeGetPoly(f,n,&q);
 printf("m=%d",m);
 printPoly(q,m);
 
 printDerivPoly(p,m);

 double p1[]={3,4,5};
 addPoly(f,p1,3,4);
 readFile(f);

 deletePoly(f,1);
 readFile(f);

 replacePoly(f,1,1,2.0);
 readFile(f);

 Poly_Coef x;
 inputCoef(&x);
 replaceStruct(f,2,x);
 readFile(f);
  */
// if(q) free(q);
}

