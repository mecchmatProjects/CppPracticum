
#include <iostream>
#include <cmath>

using namespace std;

double func(double x){
    double y = (x+1);
    return y*y*y*y*y;
}

int main() {
    double x, y;

    printf("x= ");

    cin  >> x;

    y = func(x);
    printf(" y=%lf", y);
    if (func(-1) != 0 ){
        printf("smth incorrect");
    }
    else {
        printf("\nPERFECT");
    }



    return 0;
}
