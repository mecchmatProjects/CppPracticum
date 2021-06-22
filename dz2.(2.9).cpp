#include <iostream>
#include <cmath>
using namespace std;
double vo(double r, double h)
{
double v;
v = M_PI * pow( r,2 ) * h;
return v;
}
int main()
{
double V, r, h;
cin >> r >> h;
V = vo(r,h);
cout << V << endl;
}

