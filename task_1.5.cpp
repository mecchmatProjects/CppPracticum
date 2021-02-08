
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a, b, c;

    cout << "  Type   a  b c:  ";

    cin  >> a >> b >> c;

    float p = (a+b+c)/2;
    float S = sqrt(p*(p-a)*(p-b)*(p-c));

    printf("Result = %f", S);


    return 0;
}
