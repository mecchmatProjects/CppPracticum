#include <stdio.h>
#include <math.h>
/*
  Використовуючи файл F, компоненти якого є дійсними числами, побудувати
  файл G, що містить усі числа з файлу F, які менші по модулю за задане число $a>0$.
  Послідовність чисел зберігається. Після цього видалити всі елементи з файлу F, 
  які менші по модулю за число $a$.
*/

int main(){

  const char* fname = "F.dat";
  
  FILE* F = fopen(fname,"wb"); // open file binary, for writing
  if(F==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }

  int n;
  printf("n=");
  scanf("%d",&n);
  double x;
  for(int i=0;i<n;i++){
     printf("x=");
     scanf("%lf",&x);
     fwrite(&x,1,sizeof(x),F); // write x to file F  
  }
  fclose(F);

  double a;
  printf("a=");
  scanf("%lf",&a);
  
  F = fopen(fname,"rb");

  double mas[10];
  const char* fname2 = "G.dat";
  FILE* G = fopen(fname2,"wb");
   int i=0;
   int k=0;
  while(1){
     if(feof(F)) break; 
     fread(&x,1,sizeof(double),F); // read 1 double from F
     //printf("xF%d=%lf, ",i,x);
     if(fabs(x)<a){
     //printf("xG%d=%lf, ",i,x);
        fwrite(&x,1,sizeof(x),G); 
     }
     else{
        mas[k++] = x;
     }
     i++;
  }

  fclose(F);
  fclose(G);

  G = fopen(fname2,"rb");
  i=0;
  while(1){
     if(feof(G)) break; 
     fread(&x,1,sizeof(double),G); // read 1 double from F
     printf("x%d=%lf, ",i++,x);
  }
  fclose(G);

  F = fopen(fname,"wb");
  
  fwrite(mas,k,sizeof(double),F);

  F=freopen(fname,"rb",F);
  i=0; 
  while(1){
     if(feof(F)) break; 
     fread(&x,1,sizeof(double),F); // read 1 double from F
     printf("x%d=%lf, ",i++,x);
  }
  fclose(F);



}
