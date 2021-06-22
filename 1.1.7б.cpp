#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a;
    double b;
    double c;
    double x;
    cout << " a: ";
    cin >> a;
    cout << " b: ";
    cin >> b;
    cout << " c: ";
    cin >> c;
    if ((b * b - 4 * a * c) >= 0) 
    {
        x = sqrt((-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a));
        cout << "Перший корінь " << x << endl;
        x = sqrt((-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a));
        cout << "Другий корінь " << x << endl;
        x = -sqrt((-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a));
        cout << "Третій корінь " << x << endl;
        x = -sqrt((-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a));
        cout << "Четвертий корінь " << x << endl;
    }
    else
    {
        cout << "Дискримінант менше 0" << endl;
    }

    return 0;
}
