
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Task 10" << endl;
    double r, h;
    cout << "Enter r and h: ";
    cin >> r >> h;
    cout << endl;
    double V = (1.0/3.0)*M_PI*pow(r, 2)*h;
    cout << "V = " << V << endl;
}