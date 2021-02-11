#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;



int main()
{
    cout << "x  | 1 | 2 | 3 | 4 | 5\n";
    cout << "--- +---+---+---+---+---\n";
    cout  << setprecision(3) << "F(x)| " << sqrt(1) << " | " << sqrt(2) << " | " << sqrt(3) << " | " << sqrt(4) << " | " << sqrt(5);
    return 0;
}