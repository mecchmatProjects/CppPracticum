#include <stdio.h> 
//#include <math.h>
int main() { 
 //float y = 6.673 * pow(10, -11);
 float y = 6.673e-11;
 float m1, m2, r; 
 double F; 
 printf("Enter an m1: "); scanf("%f", &m1); 
 printf("Enter an m2: "); scanf("%f", &m2);
 printf("Enter an r: "); scanf("%f", &r);
 F = (y*m1*m2)/(r*r);
 printf("F=%le", F);
}
