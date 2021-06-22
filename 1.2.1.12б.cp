#include <iostream>
#include <cmath>
using namespace std;

double sum(int n, int u, int v);
int fact(int n);

int main()
{
    int u(0), v(0);
    int n;

    cout << "n = ";
    cin >> n;

    cout << "u = ";
    cin >> u;

    cout << "v = ";
    cin >> v;

    cout << "\nSum = " << sum(n, u, v) << "\n\n";

    return 0;
}



int fact(int n)
{
    return (n == 0) || (n == 1) ? 1 : n * fact(n - 1);
}

double sum(int n, int u, int v)
{
    double sum = 0;
    int a = u;
    int b = v;

    sum += a * b / fact(1 + 1);

    for (int i = 2; i <= n; i++)
    {
        a += 2 * b;
        b += 2 * pow(a - 2*b, 2);

        sum += a * b / fact(i + 1);
    }

    return sum;
}
