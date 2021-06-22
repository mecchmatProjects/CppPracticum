#include <iostream>
#include <math.h>
using namespace std;


const double PI = 3.1415926;

int main()
{
    cout << "Enter length of the semiaxises: ";
    double a, b = 0;
    cin >> a >> b;

    cout << endl;

    double area = PI * a * b;

    cout << area;
    return 0;
}