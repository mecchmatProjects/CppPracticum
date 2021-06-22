#include <iostream>
using namespace std;

int main() {
    string in;
    int sum = 0;

    cin >> in;
    for (int i = 0; i < in.length(); i++) {
        if (isdigit(in[i])) {
            sum += in[i] - '0';
        }
    }

    cout << sum << ' ' << in.length() << endl;
    if (sum == in.length()) {
        cout << "Equal" << endl;
    } else {
        cout << "Not Equal" << endl;
    }

    return 0;
}
