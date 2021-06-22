#include <iostream>
using namespace std;

unsigned long long int countRec(int n, int sum)
{
    if (n == 0)
        return sum == 0;

    if (sum == 0)
        return 1;
    unsigned long long int ans = 0;

    for (int i=0; i<=9; i++)
        if (sum-i >= 0)
            ans += countRec(n-1, sum-i);

    return ans;
}
unsigned long long int finalCount(int n, int sum)
{
    unsigned long long int ans = 0;

    for (int i = 1; i <= 9; i++)
        if (sum-i >= 0)
            ans += countRec(n-1, sum-i);

    return ans;
}

int main()
{
    int n = 3, sum = 5;
    cout << finalCount(n, sum);
    return 0;
}
