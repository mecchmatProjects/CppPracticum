#include <iostream>
#include <cmath>
using namespace std;

float identity_f(float x , float a) {
    float func = a*x;
    if ( x >= 0)
    return 0;
    else 
    return func;
}

float identity_derivative(float x , float a) {
    float func = a;
    if ( x >= 0)
    return 0;
    else
    return func;
}
int main()
{
double x ;
double a ;
cin >> x;
cin >> a;
float result = identity_f(x , a);
float result2 = identity_derivative(x , a);
printf("Identity = %lf\n", result);
printf("Derivative = %lf", result2);
}
