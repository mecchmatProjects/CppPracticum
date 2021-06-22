#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, z, r, h;
    cout << "Enter point coordinates: ";
    cin >> x >> y >> z;
    cout << "Enter r and h: ";
    cin >> r >> h;
    double l = sqrt(pow(x, 2) + pow(y, 2));
    if(z >= 0 && z <= h && l <= r)
        cout << "Point is inside the cylinder.\n";
    else
        cout << "Point is outside the cylinder.\n";
    return 0;
}