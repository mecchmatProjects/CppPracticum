#include <iostream>
#include <cmath>
using namespace std;

double sigmoid(double x) {
    return 1.0/(1 + exp(-1*x));
}

double sigmoid_derivative(double x) {
    return exp(-1*x)/pow((1 + exp(-1*x)), 2);
}

int main() {
    double x;
    cout << "Enter x: ";
    cin >> x;
    cout << endl;
    cout << "sigmoid(x) = " << sigmoid(x) << endl;
    cout << "sigmoid'(x) = " << sigmoid_derivative(x) << endl;
    return 0;
}