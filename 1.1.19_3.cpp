#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool isNearlyZero(float x) {
    return fabs(x) < (fabs(x) < 0.000001);
}
bool isNearlyEqual(double x, double y){
    return (fabs(x-y)<= DBL_EPSILON* 2*(fabs(x) + fabs(y)));
}

float sinc(float x) {
    if (x == 0) {
        float func = 1;
        return func;
    } else {
        float func = (sin(x)) / x;
        return func;
    }

}

float sinc_derivative(float x) {
    if (isNearlyZero(x)) return DBL_MAX;
    else if (x != 0) {
        float func = ((cos(x)) / x) - (sin(x)) / (x * x);
        return func;
    }
    return 0;
}


int main() {

    float x;

    printf("Your x value is ");

    cin >> x;

    if(isNearlyZero(sinc(-2)-0)){
        printf("ok1");
    }

    if(isNearlyEqual(sinc_derivative(-2),0)){
        printf("ok2");
    }
    printf("Identity = %lf\n", sinc(x));
    printf("Derivative = %lf\n", sinc_derivative(x));


    return 0;
}