#include <iostream>
using namespace std;

int main() {
    string in;
    string res;
    string tmp;
    int maxLen = 0;
    int tmpLen;

    getline(cin, in);

    for (int i = 0; i < in.length(); i++) {
        if ((in[i] >= 'a' && in[i] <= 'z') ||  (in[i] >= 'A' && in[i] <= 'Z')) {
            tmp = in[i];
            tmpLen = 1;
            i += 1;
            for (; (in[i] >= 'a' && in[i] <= 'z') ||  (in[i] >= 'A' && in[i] <= 'Z'); i++) {
                tmp += in[i];
                tmpLen += 1;
            }
            if (tmpLen >= maxLen) {
                res = tmp;
                maxLen = tmpLen;
            }
        }
    }

    cout << res;

    return 0;
}