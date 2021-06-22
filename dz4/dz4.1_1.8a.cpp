#include <iostream>
using namespace std;

int main(){
    float a1, b1, c1, a2, b2, c2;
    cout << "Enter a1, b1, c1: ";
    cin >> a1 >> b1 >> c1;
    cout << "Enter a2, b2, c2: ";
    cin >> a2 >> b2 >> c2;

    if ((a1 / b1) == (a2 / b2)){
        if ((c1 / b1) == (c2 / b2)) cout << "inf solutions" << endl;
        else cout << "0 solutions" << endl;
    }
    else cout << "1 solution: " << ((c2 / b2) - (c1 / b1)) / ((a1 / b1) - (a2 / b2)) << endl;
    
    return 0;
}