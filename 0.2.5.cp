#include <iostream>
#include <math.h>
 // Завдання 0.2.5
double getL(double c, double a, double b) {
    double s = a + b;
    return sqrt(a * b * (s + c) * (s - c))/s;
}
int main(void) {
 double a, b, c, amed, bmed, cmed, h1, h2, h3, p, S ;
 printf("Введіть довжини a, b, c (a, b, c не можуть бути менше або дорівнювати 0): \n");
 scanf("%lf %lf %lf", &a, &b, &c);
 bmed=0.5*sqrt(2*a*a+2*c*c-b*b);
 amed=0.5*sqrt(2*b*b+2*c*c-a*a);
 cmed=0.5*sqrt(2*a*a+2*b*b-c*c);
 printf("bmed=%8lg\n",bmed);
 printf("amed=%8lg\n",amed);
 printf("cmed=%8lg\n",cmed);
//вычисляем полупериметр
p=(a+b+c)/2;
//вычисляем площадь треугольника
S=sqrt(p*(p-a)*(p-b)*(p-c));
//вычисляем высоты
h1=2*S/a;
h2=2*S/b;
h3=2*S/c;
printf("%lf %lf %lf\n", h1, h2, h3);
std::cout << "Довжини бісекрис A, B і C дорівнюють " << getL(a, b, c) << ", " <<getL(b, a, c) << " и " << getL(c, a, b) << ".";
    
    
    
 return 0;
    
    
}

