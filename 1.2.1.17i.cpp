#include<iostream>
#include <cmath>
using namespace std;

double f(double x) 
{
    int n = 1;
    int k = 1;
    double kx = 1;
    double Y = 0;
    double Y1 = 1;
    while (fabs(Y - Y1) > 0.0001) {
        n++;
        k *= -1;
        kx *= x;
        Y = Y1;
        Y1 = Y + k * n * kx;
        cout << Y1 << endl;
    }
    return Y1;
}

int main() {
    float x = 1;
    while (x >= 1) {
        cin >> x;
    }
    cout<< f(x);
}