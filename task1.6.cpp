
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    cout << "Task 6" << endl;
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    if(x < 0) {
        cout << "x should be greater than 0.";
        return 0;
    }
    if(x > 10000) {
        cout << "x should be less than 10000.";
        return 0;
    }
    double res = pow(x, 8);
    cout << fixed << setprecision(4);
    cout << "x^8 = " << res << endl;
    cout << defaultfloat;
    return 0;
}
