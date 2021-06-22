#include <iostream>
#include <type_traits>
#include <sstream>

using namespace std;

template<class T >

string sum(T* v, size_t n) {
    string res;
    if (is_same<T, char>::value) {
        for (int i = 0; i < n; ++i) {
            res += v[i];
        }
        return res;
    }
    if (is_same<T, string>::value) {
        for (int i = 0; i < n; ++i) {
            res += v[i];
        }
        return res;
    }
    if (is_same<T, int>::value || is_same<T, double>::value) {
        T r = 0;
        for (int i = 0; i < n; ++i) {
            r += v[i];
        }
        std::ostringstream ost;
        ost << r;
        res = ost.str();
        return res;
    }
    if (is_same<T, int**>::value) {
        T r = 0;
        for (int i = 0; i < n; ++i) {
            r += v[i];
        }
        std::ostringstream ost;
        ost << r;
        res = ost.str();
        return res;
    }

}
template<class T >
string sum_(T* v, size_t n) {
    string res = "{";
    for (int i = 0; i < n; ++i) {
        int n = v[i][0];
        std::ostringstream ost;
        ost << n;
        res += ost.str();
        res += ",";
    }
    int k = res.length();
    res[k - 1] = '}';

    return res;

}

int main() {
    int n = 3;
    int v1[] = { 1, 2, 3 };
    int r = stoi(sum(v1, n));
    cout << "sum(v1,3)=" << r << endl;
    double v2[] = { 1, 2, 3 };
    double r2 = stod(sum(v2, n));
    cout << "sum(v2,3)=" << r2 << endl;
    string v3[] = { "ad", "ede", "egr" };
    string r3 = sum(v3, n);
    cout << "sum(v3,3)=" << r3 << endl;
    char v4[] = { 'a', 'b', 'c' };
    string r4 = sum(v4, n);
    cout << "sum(v4,3)=" << r4 << endl;
    int v5[3][2] = { {4, 5}, {8}, {9} };
    string r5 = sum_(v5, n);
    cout << "sum(v5,3)=" << r5 << endl;

}
