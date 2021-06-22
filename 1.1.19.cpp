#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool isNearlyZero(float x){
    return fabs(x) <  (fabs(x)<0.000001);
}

float onestep(float x) {
    if (x >= 0){
        float func = 1;
        return func;
    }else{
        float func = 0;
        return func;
    }

}

float onestep_derivative(float x){
    if (isNearlyZero(x)) return DBL_MAX;
    return 0;
}
float reLu(float x){
    float func = fmax(0, x);
    return func;
}

float reLu_derivative(float x){
    if(isNearlyZero(x)) return  0.5;
    else if(x<0){
        return 0;
    }
    return 1;

}


int main() {

    float x;

    printf("Your x value is ");

    cin >> x;

    printf("Identity1 = %lf\n", onestep(x));
    printf("Derivative1 = %lf\n",onestep_derivative(x));

    printf("Identity2 = %lf\n", reLu(x));
    printf("Derivative2 = %lf",reLu_derivative(x));


    return 0;
}