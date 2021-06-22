#include <iostream>
#include <cmath>

using namespace std;

typedef double PTYPE;

class Polinom
{
    public:
    int n;
    PTYPE a[256];
    Polinom()
    {

    };
    Polinom(int k, PTYPE mas[256])
    {
        n = k;
        for (int i = 0; i < n; ++i)
        {
            a[i] = mas[i];
        }
    };
    void input();
    void output();
    void pohidna();
    PTYPE calculate(double x);
    void add(int k, PTYPE* a1, PTYPE* res);
    void subtraction(int k, PTYPE* a1, PTYPE* res);
    void mul(int k, PTYPE* a1, PTYPE* res);
};


class PowerPolinomException : public exception {
public:
    const char* what() const throw() {
        return "Power is not correct";
    }
};
class ValueCoefficientException : public exception
{
public:
    const char* what() const throw() {
    return "Coefficient in polinom is not correct";
}
};

void Polinom::input()
{
    double r;
    cout << "Input n:";
    cin >> r;
    n = r;
    if (n != r)
    {
        throw PowerPolinomException();
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "x^" << i << "=";
        cin >> a[i];
    }
}

void Polinom::output()
{
    if (n == 0) return;
    if (n == 1)
    {
        cout << a[0];
        return;
    }
    cout << "\n" << a[n - 1] << "x^" << (n - 1);
    for (int i = n - 2; i > 0; --i)
    {
        if (a[i] >= 0)
        {
            cout << "+";
        }
        cout << a[i] << "x^" << (i);
    }
    if (a[0] >= 0)
    {
        cout << "+" << a[0];
    }
    else
    {
        cout << a[0];
    }

}

void Polinom::pohidna()
{
    cout << "\npohidna:" << endl;
    PTYPE pohidna[256];
    for (int i = 0; i < n; ++i)
    {
        pohidna[i] = a[i + 1] * (i + 1);
    }
    Polinom po(n-1, pohidna);
    po.output();
}

PTYPE Polinom::calculate(double x)
{
    double res = 0;
    for (int i = 0; i < n; ++i)
    {
        res += a[i] * pow(x, i);
    }
    return res;
}

void Polinom::add(int k, PTYPE* a1, PTYPE* res)
{
    cout << "\nsuma" << endl;
    int ros;
    if (n >= k)
    {
        ros = n;
    }
    else
    {
        ros = k;
    }
    for (int i = 0; i < ros; ++i)
    {
        res[i] = a[i] + a1[i];
    }
    Polinom res1(n, res);
    res1.output();
}

void Polinom::subtraction(int k, PTYPE* a1, PTYPE* res)
{
    cout << "\ndifference" << endl;
    int ros;
    if (n >= k)
    {
        ros = n;
    }
    else
    {
        ros = k;
    }
    for (int i = 0; i < ros; ++i)
    {
        res[i] = a[i] - a1[i];
    }
    Polinom res1(n, res);
    res1.output();
}

void Polinom::mul(int k, PTYPE* a1, PTYPE* res)
{
    cout << "\nproduct" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            res[i + j] += a[i] * a1[j];
        }
    }
    Polinom res1(n+k - 1, res);
    res1.output();
}


int main()
{
    PTYPE res_add[256] = { 0 };
    PTYPE res_sub[256] = { 0 };
    PTYPE res_mul[256] = { 0 };
    Polinom p1;
    Polinom p2;
    p1.input();
    if (p1.n <= 0)
    {
        throw PowerPolinomException();
    }
    for (int i = 0; i < p1.n; ++i)
    {
        if (sizeof(double) != sizeof(p1.a[i]))
        {
            throw ValueCoefficientException();
        }
    }
    p2.input();
    if (p2.n <= 0)
    {
        throw PowerPolinomException();
    }
    for (int i = 0; i < p2.n; ++i)
    {
        if (sizeof(double) != sizeof(p2.a[i]))
        {
            throw ValueCoefficientException();
        }
    }
    p1.output();
    p2.output();
    p1.pohidna();
    cout << "\n" << p1.calculate(4);
    p1.add(p2.n, p2.a, res_add);
    p1.subtraction(p2.n, p2.a, res_sub);
    p1.mul(p2.n, p2.a, res_mul);

}