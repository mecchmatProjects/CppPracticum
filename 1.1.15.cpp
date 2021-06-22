#include <iostream>
#include <cmath>
using namespace std;
double length(double x1, double y1, double x2,  double y2)
{
  double l = sqrt ( pow(x2-x1,2) + pow(y2-y1,2) );
  return l;
}
double sqr(double a, double b, double c)
{
  double p = (a+b+c)/2;
  double S = sqrt(p*(p-a)*(p-b)*(p-c));
  return S;
}
int main()
{
  double x1,y1,x2,y2,x3,y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  double S,S1;
  double a,b,c;
  a = length(x1, y1, x2, y2);
  b = length(x2, y2, x3, y3);
  c = length(x1, y1, x3, y3);
  S = sqr(a, b, c);
  double xa,xb,xc;
  xa = length(x1, y1, 0, 0);
  xb = length(x2, y2, 0, 0);
  xc = length(x3, y3, 0, 0);
  S1 = sqr(xa, xb, xc);
  if (abs(S) > abs(S1))
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}
