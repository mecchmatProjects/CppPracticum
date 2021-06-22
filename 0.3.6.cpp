#include <iostream>
#include <math.h>

using namespace std;

float identity_f(float x) {
    float func = 1 / (1 + exp(-x));
    return func;
}

float identity_derivative(float x) {
    float func = (exp(-x)) / ((1 + exp(-x)) * (1 + exp(-x)));
    return func;
}

int main() {

    float x;

    printf("Your x value is ");

    cin >> x;
    float result = identity_f(x);
    float result2 = identity_derivative(x);
    printf("Identity = %lf\n", result);
    printf("Derivative = %lf", result2);


    return 0;
}