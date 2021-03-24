#include <stdio.h>
#include <stdbool.h>

// Rational 11.3 (4.0.3)
typedef struct {
int numerator; // чисельник
unsigned int denominator; // знаменник
} Rational;


int input(Rational* x){
 
 scanf(" %d",&x->numerator);
 scanf(" %u",&x->denominator);
 
 return 0;
}


void vyvod(const Rational x){
  printf("\nR= %d / %u",x.numerator,x.denominator);
}


Rational add(const Rational a, const Rational b){
   Rational c;

   c.numerator = (int)(a.numerator * b.denominator) +  (int)(b.numerator * a.denominator);
   c.denominator = a.denominator * b.denominator;

   return c;
}

Rational mul(const Rational a, const Rational b){
   Rational c;

   c.numerator = a.numerator * b.numerator ;
   c.denominator = a.denominator * b.denominator;

   return c;
}

bool cmp(const Rational a, const Rational b){
   return a.numerator*b.denominator > b.numerator*a.denominator;
}


unsigned gcd(unsigned a, unsigned b){
    if(a==0) return b;
    if(b==0) return a; 
    if(a>b) return gcd(b,a%b);
    else return gcd(a,b%a);
}


Rational reduce(const Rational x){

   unsigned d=gcd(x.numerator, x.denominator);
    Rational z;
 
    z.numerator = (int)x.numerator / d;
    z.denominator = x.denominator /d;
   return z;
}

void reduce1 (Rational* x){
   unsigned d=gcd(x->numerator, x->denominator);
    Rational z;
 
    x->numerator /= d;
    x->denominator /= d;
}



int main(){

  Rational x,y,z;
  input(&x);
  vyvod(x);
  input(&y);
  vyvod(y);

  z = add(x,y);
  reduce1(&z);
  vyvod(z);

  Rational z1= mul(x,y);
  vyvod(reduce(z1));
   printf("\nz>z1==%d",cmp(z,z1));
  
}



