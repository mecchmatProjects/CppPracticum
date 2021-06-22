#include <iostream>
#include <math.h>

using namespace std;

float identity(float x) {
    float f = (log(1 + exp(x)));
    return f;
}

float identity_derivative(float x) {
    float f = exp(x) / (1 + exp(x));
    return f;
}

int main() {

    float x;

    printf("x= ");

    cin >> x;
    float result1 = identity(x);
    float result2 = identity_derivative(x);
    printf("Identity = %lf\n", result1);
    printf("Derivative = %lf\n", result2);


    return 0;
}
