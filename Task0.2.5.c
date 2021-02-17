#include <iostream>
#include <cmath>
using namespace std;

double median(double a, double b, double c){
  return sqrt( 2*a*a + 2*b*b - c*c )/2.0;
}

double bissectr(double a, double b, double c){
  return 2*sqrt( a*b*p*(p - c) )/(a + b);
}

double high(double a, double b, double c){
  return 2*sqrt( p*(p - a)*(p - b)*(p - c) )/a;
}
int main() {
    cout << "Task 5" << endl;
    double a, b, c;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;
    cout << endl;
    double m1 = sqrt( 2*a*a + 2*b*b - c*c )/2.0;
    double m2 = sqrt( 2*a*a + 2*c*c - b*b )/2.0;
    double m3 = sqrt( 2*b*b + 2*c*c - a*a )/2.0;
    double p = (a + b + c)/2.0;
    double b1 = 2*sqrt( a*b*p*(p - c) )/(a + b);
    double b2 = 2*sqrt( a*c*p*(p - b) )/(a + c);
    double b3 = 2*sqrt( b*c*p*(p - a) )/(b + c);
    double h1 = 2*sqrt( p*(p - a)*(p - b)*(p - c) )/a;
    double h2 = 2*sqrt( p*(p - a)*(p - b)*(p - c) )/b;
    double h3 = 2*sqrt( p*(p - a)*(p - b)*(p - c) )/c;
    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;
    cout << "m3 = " << m3 << endl;
    cout << "b1 = " << b1 << endl;
    cout << "b2 = " << b2 << endl;
    cout << "b3 = " << b3 << endl;
    cout << "h1 = " << h1 << endl;
    cout << "h2 = " << h2 << endl;
    cout << "h3 = " << h3 << endl;
    return 0;
}
