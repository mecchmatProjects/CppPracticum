

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float x, i;

    cout << " Type a number:  ";

    cin  >> x ;

    cout << "Result is " <<  modf(x, &i);
    cout << "\n  Int part is " << int(x);
    cout << "\n  The biggest num is " << int(x) +1;
    cout << "\n  The smallest num is " << int(x) -1;
    cout << "\n  Rounded num is " << round(x);
    return 0;
}
