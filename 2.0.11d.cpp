#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int fullSquares(int *arr, unsigned n)
{
    int count = 0;
    
    for (size_t i = 0; i < n; i++)  
    {
        double temp = sqrt(arr[i]);
        if (temp - (int)temp == 0)      
            ++count;
    }

    return count;
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

    cout << "\nfullSquares(arr) = " << fullSquares(arr, n) << "\n\n";

    delete[]arr;
    return 0;
}
