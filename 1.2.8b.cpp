#include <iostream>
using namespace std;

int main ()
{   double sum = 0;
    int n = 100;
    while(n > 0) sum = sqrt(3*n-- + sum);
    printf("%lf", sum);
}
