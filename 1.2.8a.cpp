#include <iostream>
using namespace std;

int main ()
{   int n = 4;
    double s =sqrt(2);
    for(int i=1;i<n;i++)
        s=sqrt(s+2);
    printf("%lf", s);
}
