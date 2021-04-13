#include <stdio.h>
#include <stdlib.h>


typedef struct Rect{
  unsigned num;
  float x;
  float y;

} Rect;

int vvod(Rect* r){
  
  
  printf("input n, x,y :");
  scanf("%u",&(r->num));
  scanf("%f",&(r->x));
  scanf("%f",&(r->y));
  return EXIT_SUCCESS;
}

int addRect(char* fname){

  unsigned n;
  Rect r1;
  scanf("%d", &n);

  FILE* f = fopen(fname, "wb");
  
  for(unsigned i=0; i<n;++i){
     vvod(&r1);
     fwrite(&r1,1,sizeof(r1),f);
  }

  fclose(f);
}


unsigned maxrect(char * fname){

  unsigned n;
  Rect r1;
  FILE* f = fopen(fname, "rb");
  double maxarea = 0;
  while(!feof(f)){
     
     int r =fread(&r1,sizeof(r1),1,f);
     if(r<1) break;

     float w = r1.x;
     float h = r1.y;
     
     if(w*h>maxarea){
        maxarea = w*h;
        n = r1.num;
    }     

  }

  fclose(f);

  printf("Max sqr = %lf", maxarea);
  return n;
}

int main(){

  addRect("rect.dat");

  printf("%u", maxrect("rect.dat")); 
}


