#include<iostream>
#include <cstring>
#include <cmath>

#define P 3;

using namespace std;

long long customHash(const string& str) {
    long long p = 1;
    long long pow_2 = pow(2, 32);

    long long res = 0;
    for (int i = 0; i < str.length(); ++i) {
        char ch = str[i];
        p *= P;
        ch *= p;
        ch = ch % pow_2;
        res += (res + ch) & ((1 << 32) - 1);
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    cout << customHash(str);
}
