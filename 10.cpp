#include <iostream>
using namespace std;

int isPower2(int a) {
    return !(a&(a-1));
}

int isPower2Cycle(int a) {
    if (a == 1) {
        return 1;
    } else if ((a>>1) << 1 == a) {
        return isPower2Cycle(a>>1);
    }
    return 0;
}

int main() {
    cout << "20 is power of 2: " << isPower2Cycle(20) << endl;
    cout << "16 is power of 2: " << isPower2Cycle(16) << endl;

    return 0;
}
