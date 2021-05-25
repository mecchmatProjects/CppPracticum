/*Завдання 11, перша домашня робота*/
#include <cstdio>

int main(){

    double m, v;
    printf("Input m and v: ");
    scanf("%lf %lf", &m, &v);

    float Ek = m*v*v/2;
    printf("Kinetic energy: %f", Ek);

}
