//1.2.19e

#include <iostream>
using namespace std;

double function(double x, int k){
    double xk = x;
    for (int i = 1; i <= k; i++)
        xk *= x*x/(2*k * (2*k + 1));
    return xk;
}

int main() {
    int k;
    double x;
    cin >> x >> k;
    cout << function(x, k) << endl;
    return 0;
}