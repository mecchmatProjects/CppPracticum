#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

using namespace std;
double A, B, C, arifm, geom;

int main() {
    printf ("A=");
    scanf("%lf,", &A);
    printf ("B=");
    scanf("%Elf", &B);
    printf ("C=");
    scanf("%lf", &C);
    arifm=(A+B+C)/3;
    geom=3 / (1 / A + 1 / B + 1 / C);
    cout<<"format = "<<arifm<<" " <<geom<<endl;
    cout<<scientific<<"scientific format = "<<arifm<<" " <<geom<<endl;
    return 0;
}


