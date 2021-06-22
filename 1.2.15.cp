#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    int previous(0), current(1);

    while (current != 0)
    {
        cin >> current;
        if (current * previous < 0)
            ++count;
        previous = current;
    }

    cout <<  "\nSign changes:\t" << count << endl;

    return 0;
}
