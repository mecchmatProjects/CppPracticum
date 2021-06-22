#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float r, h;

   printf("  Type  r and h :  ");

    cin >> r >> h;

    double V = (h*r*r*M_PI)/3;

    printf("Result = %lf", V);


    return 0;
}
