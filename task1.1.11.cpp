#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, r1, x2, y2, r2;
    cout << "Enter x1, y1 and r1: ";
    cin >> x1 >> y1 >> r1;
    cout << "Enter x2, y2 and 2: ";
    cin >> x2 >> y2 >> r2;
    double l = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    if(l > (r1 + r2)) {
        cout << "Circles not intersect." << endl;
    }
    else {
        cout << "Circles intersect." << endl;
    }
}