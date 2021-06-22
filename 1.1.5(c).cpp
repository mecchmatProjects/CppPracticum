#include <iostream>
#include <cmath>
using namespace std;

int main()
{
double x ;
cin >> x;
if ( x >= 0)
{
    printf("%lf" , sin(x));
}  
else
{
    printf("%lf" , -sin(-x));
}
}
