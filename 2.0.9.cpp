#include <iostream>
#include <cmath>

using namespace std;


double refactor(int a) {
    int counter = 0;
    long long int n = 0;
    int k, m = 0;
    while (a) {
        k = a % 2;

        a = a / 2;
        n += k * pow(10, m);
        m++;

    }
    return n;

}

int main() {
    int N;
    int counter = 0;
    cout << "input array using spaces: ";
    cin >> N;
    int nums[N];


    for (int i = 0; i < N; i++) {
        cout << "[" << i << "]" << ": ";
        cin >> nums[i];
    }

    for (int i = 0; i < N; ++i) {
        int c = 0;
        int dnum = refactor(nums[i]);
        while (dnum > 0) {
            int k = dnum % 10;
            if (k == 1) {
                c++;
            }
            if (c == 5) {
                counter++;
            }
            dnum /= 10;

        }
    }
    cout << "Numbers with 5bits, which equal 1: " << counter;
    return 0;
}
