
#include <stdio.h>
#include <ctype.h>
#include <math.h>

/*
 Створить файл, який містить відомості про прямокутники: вказано номер
  прямокутника у файлі, координати (дійсні числа) верхнього лівого кута та
  нижнього правого кута прямокутника. Скласти функцію пошуку
  прямокутника з найбільшою площею й визначення цієї площі.
*/

typedef struct{
  unsigned num; //4 aligns to 8   
  double x1;//8 byte
  double y1;
  double x2;
  double y2;
} Rectangle; // 40 bytes without alignment

int input(Rectangle* r){
  printf("n=");
  scanf("%u",&r->num);

  printf("x,y");
  scanf(" %lf %lf",&r->x1, &r->y1);

  printf("x,y");
  scanf(" %lf %lf",&r->x2, &r->y2);
  return 0;
}

void printRect(const Rectangle r){
   printf("\nR=%u (%lf,%lf)--(%lf,%lf)",r.num,r.x1,r.y1,r.x2,r.y2);
}


int writeRectToFile(const char* fname){
  FILE* fp = fopen(fname,"wb"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }

  char c;
  Rectangle r;
  do{
   printf("Input rectangle:, num, (x1,y1)-(x2,y2)");
   input(&r);
   fwrite(&r,1,sizeof(r),fp); 
   printf("continue?y/n");
   int p=scanf(" %c",&c);
   //printf("PP %d %c\n", p, c);
   //c= getchar(); 
   if(tolower(c)=='n') break; 
  }while(1);
   
  fclose(fp);
}


int readFile(const char * fname){
  FILE* fp = fopen(fname,"rb"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }
  Rectangle x;
  while(!feof(fp)){

     int res = fread(&x,sizeof(x), 1, fp); // read 1 struct from F
     
     if(res<1){ printf("EOF %d\n",res); break;}
     printRect(x);
  }
  
  fclose(fp);
}

int maxArea(const char * fname){
  FILE* fp = fopen(fname,"rb"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }

  Rectangle x;
  double maxArea=0;
  unsigned ind=0;

  while(!feof(fp)){

     int res = fread(&x,sizeof(x), 1, fp); // read 1 rectangle from F
     
     if(res<1){
      // printf("EOF %d",res); 
      break;
     }
     //printRect(x);
     double area = fabs(x.x1-x.x2)*fabs(x.y1-x.y2);
     if(area>maxArea){
        ind = x.num;
        maxArea = area; 
     } 
  }
  
  fclose(fp);

  printf(" max area = %lf for rectangle %d", maxArea, ind);

  return ind;
}

int main(){

  char fname[10] = "Rect1.dat";
  
  writeRectToFile(fname); 

  readFile(fname);

  maxArea(fname);
}
