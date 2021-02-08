
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a, b, c;

    cout << "  Type   a  b c:  ";

    cin  >> a >> b >> c;

    float d = sqrt(b*b -4*a*c);
    float x1 = (-b +d)/(2*a);
    float x2 = (-b -d)/(2*a);
    printf(" %f \n %f", x1, x2);


    return 0;
}
