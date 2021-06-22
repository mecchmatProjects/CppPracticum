#include <iostream>
using namespace std;

void digit(int n, int k)
{
    if (n < 0)
        n = -1 * n;

    if (n % 10 == k)
    {
        cout << "Yes\n";
        return;
    }
    else if (n / 10 > 0)
        digit(n / 10, k);
    else
        cout << "no" << endl;
}
int main()
{
    digit(1267, 5);
    return 0;
}