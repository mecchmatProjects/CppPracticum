#include <iostream>
using namespace std;


int main(){
    int a, b, c;
    cout << "A=";
    cin >> a;
    cout << "B=";
    cin >> b;
    cout << "C=";
    cin >> c;

    cout << "Seredne arifmetichne: " << (float) (a + b + c) / 3 << endl;
    cout << "Seredne garmonichne: " << (float) (3 * a * b * c) / (a * b + b * c + a * c) << endl;
    cout << scientific;
    cout << "Seredne arifmetichne: " << (float) (a + b + c) / 3 << endl;
    cout << "Seredne garmonichne: " << (float) (3 * a * b * c) / (a * b + b * c + a * c) << endl;

    return 0;
}