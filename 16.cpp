#include <iostream>
#include <cmath>
using namespace std;

class Equation {
public:
    double a;
    double b;
    double c;
    double x1;
    double x2;
    double ext;
    double arg1;
    double arg2;
    bool control = true;

    void input() {
        cout << "a*x^2+b*x+c=0 input a b c";
        cin >> a >> b >> c;
    }

    void roots() {
        double D = b * b - 4 * a * c;
        if (D < 0) {
            cout << "The equation has no solutions" << endl;
            control = false;
        }
        if (D == 0)
        {
            x1 = -b / (2 * a);
            x2 = -b / (2 * a);
            cout << "x1=x2=" << x1;
        }
        if (D > 0)
        {
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            cout << "x1=" << x1 << ", " << "x2=" << x2 << endl;
        }
    }

    void extreme() {
        ext = -b / 2 / a; //Знаходимо похідну a*x^2+b*x+c=0 і знаходимо корінь
        cout << "Extremum of the function" << a << "x^2+" << b << "x+" << c << endl;
        cout << "x=" << ext << endl;
    }

    void intervals() {
        arg1 = 2 * a * (ext - 1) + b;
        arg2 = 2 * a * (ext + 1) + b;
        if (arg1 > 0 && arg2 < 0) {
            cout << "growth interval:" << "[-∞; " << ext << "]" << endl;
            cout << "declining interval:" << "[" << ext << "; +∞]" << endl;
        }
        if (arg1 < 0 && arg2>0) {
            cout << "declining interval:" << "[-∞; " << ext << "]" << endl;
            cout << "growth interval:" << "[" << ext << "; +∞]" << endl;
        }
    }
};

int main() {
    int n = 4;
    Equation eq;
    eq.input();
    eq.roots();
    eq.extreme();
    eq.intervals();
    Equation mas[n];
    int j = 0;
    double mas_roots[2 * n];
    for (int i = 0; i < n; ++i) {
        mas[i].input();
        mas[i].roots();
        if (mas[i].control) {
            mas_roots[j] = mas[i].x1;
            mas_roots[j + 1] = mas[i].x2;
            j += 2;
        }
        else continue;

    }
    double max_root = mas_roots[0];
    for (int i = 0; i < j; ++i) {
        if (mas_roots[i] > max_root) {
            max_root = mas_roots[i];
        }
    }
    cout << "Max root:" << max_root << endl;
}