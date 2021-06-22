#include <math.h>
#include <iostream>
double my_sin(double x, int n)
{
    if (n == 1 ) return sin(x);
    return sin(my_sin(x,n-1));
}

int main()
{
    double x = 0,y = 0;
    int n = 0;
    std::cout << "Enter x:";
    std::cin >> x;
    while(n<=0)
    {
        std::cout << "\n" << "Enter n: ";
        std::cin >> n;
    }

    y = my_sin(x,n);
    std::cout << "Result: " << y;

    return 0;
}