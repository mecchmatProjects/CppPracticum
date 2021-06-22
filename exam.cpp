#include <iostream>

using namespace std;

int main()
{
    int count = 6;
    int i, j, temp;
    int a[6] = { 15,3,4,11,12,13 };


    cout << "Input list ...\n";
    for (i = 0; i < count; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    int X;
    cout << "Enter X: \n";
    cin >> X;

    for (i = 0; i < count; i++)
    {
        if (a[i] > X)
        {
            for (j = count - 1; j >= 0; j--)
            {
                if (a[j] < X)
                {
                    break;
                }
            }

            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else
            {
                break;
            }
        }
    }


    cout << "Output List ...\n";
    for (i = 0; i < count; i++) {
        cout << a[i] << "\t";
    }
    return 0;
}
