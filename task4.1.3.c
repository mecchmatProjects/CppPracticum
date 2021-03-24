
#include <stdio.h>
#include <ctype.h>

typedef struct{
  unsigned num; //8  
  double x1;//8 byte
  double y1;
  double x2;
  double y2;
} Rectangle; // 40 byte

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
   printf("R=%u (%lf,%lf)--(%lf,%lf)",r.num,r.x1,r.y1,r.x2,r.y2);
}

int writeRectToFile(const char* fname){
  FILE* fp = fopen(fname,"wb"); // open file binary, for writing
  if(fp==NULL) {
     fprintf(stderr, "Error open file %s",fname);
     return -1;
  }

  char c;
  int x;
  Rectangle r;
  do{
   printf("Input rectangle:, num, (x1,y1)-(x2,y2)");
   input(&r);
   fwrite(&r,1,sizeof(r),fp); 
   printf("continue?y/n");
   int p=scanf(" %c",&c);
   printf("PP %d %c\n", p, c);
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

     int res = fread(&x,1,sizeof(x),fp); // read 1 double from F
     
     if(res!=sizeof(x)){ printf("EOF %d",res); break;}
     printRect(x);
  }
  
  fclose(fp);
}

int main(){

  char fname[10] = "Rect.dat";
  
  writeRectToFile(fname); 

  readFile(fname);

}
