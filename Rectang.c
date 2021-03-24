#include <stdio.h>


typedef struct Coord{
   float x;
   float y;
} Coord;

typedef struct Rect{
   Coord P1;
   Coord P2;
} Rect;

int input(Rect* r){
    float x1,y1,x2,y2;
   printf("x1,y1:");
   scanf(" %f",&x1);
   scanf(" %f",&y1);

   printf("x2,y2:");
   scanf(" %f",&x2);
   scanf(" %f",&y2);

    r->P1.x = x1;
    r->P1.y = y1;
    r->P2.x = x2;
    r->P2.y = y2;
}

void output(const Rect* r){

   printf("R= (%f %f) - (%f %f)",r->P1.x,r->P1.y, r->P2.x,r->P2.y);
}

int main(){

  Rect a;
  input(&a);
  output(&a);
}


