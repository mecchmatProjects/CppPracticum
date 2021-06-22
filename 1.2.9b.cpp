#include <iostream>
#include <cmath>

using namespace std;

void function(double x, unsigned n){
    double res = 0;
    double pow_x = 1;
    for (int k = 0; k <= n; k++){
        res += k * pow_x * pow(1-x, n- k);
        pow_x *= x;
    }
    cout << "result = " << res << endl;
}

int main() {
    unsigned n;
    double x;
    do{
        cout << "Input 0<x<1:" << endl;
        cin >> x;
    }while(x > 1 || x < 0);
    cout << "input n > 0 " << endl;
    cin >> n;
    function(x, n);
    return 0;
}