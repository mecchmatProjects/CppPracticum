#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int min(int *arr, unsigned n)
{
    int* sums = new int[n-1];
    for (size_t i = 1; i < n; i++)     
        sums[i-1] = arr[i] + arr[i - 1];
    
    int min = sums[0];
    for (size_t i = 1; i < n - 1; i++)  
        if (min > sums[i])
            min = sums[i];

    return min;
}

int main()
{
    unsigned n(0);

    cout << "arr[n];\n";
    cout << "n = ";
    cin >> n;
    cout << endl;
    int* arr = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        cout << "arr[" << i + 1 << "] = ";
        cin >> arr[i];
    }

    cout << "\nmin(arr) = " << min(arr, n) << "\n\n";

    delete[]arr;
    return 0;
}
