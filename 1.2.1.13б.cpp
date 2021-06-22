#include <iostream>
#include <cmath>
using namespace std;

void b_con(double& b, double& a) {
    b = 2 * b + 5 * a * a;
}
void a_con(double a[4]) {
    double tmp = a[2];

    a[2] = a[0] + a[1]/pow(2, a[3]);
    a[3] += 1;
    a[0] = a[1];
    a[1] = tmp;
}

int main() {
    int n = 2;
    double b = 1;
    double a[4] = {1, 1, 3, 2};
    double res = 0;

    a_con(a);                  // a[0] - I

    res = a[0] * b;


    for ( int i = 1; i < n; i++) {
        b_con(b, a[0]);
        a_con(a);
        res *= a[0] * b;
    }

    cout << res;

    return 0;
}

