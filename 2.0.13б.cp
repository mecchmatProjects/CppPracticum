#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std::placeholders;

double f(double x, unsigned n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return 2 * x;
    else
        return 2 * x * f(x, n - 1) - 2 * (n - 1) * f(x, n - 2);
}

std::vector<double> getCoeffs(double x, unsigned n)
{
    std::vector<double> result(n);
    auto fBound = std::bind(f, x, _1);
    for (int i = 0; i < n; i++)
        result[i] = fBound(i);

    return result;
}

int main()
{
    const double x = 1.5;
    const int n = 15;
    std::vector<double> coeffs = getCoeffs(x, n);

    std::for_each(coeffs.begin(), coeffs.end(), [](double coef) {
        std::cout << coef << " ";
    });
    std::cout << std::endl;

    return 0;
}
