
#include <iostream>


using namespace std;

int main() {
    float a, b;

    cout << "  Type  numbers a  b:  ";

    cin  >> a >> b;

    float c = (2 * a * b)/ (a + b);

    printf("%f", c);
    printf("\n %le", (a + b)/2);

    return 0;
}
