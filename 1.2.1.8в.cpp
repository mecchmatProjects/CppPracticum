#include <iostream>
using namespace std;

float rec(int n) {
    if (n == 1) {
        return 1.5;
    }
    return 1 + 1/(2 + 1/rec(n-1));
}

int main() {
    int n;
    cin >> n;
    cout << "x2n = " << rec(n);

    return 0;
}