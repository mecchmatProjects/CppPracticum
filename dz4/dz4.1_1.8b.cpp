#include <iostream>
using namespace std;

int main(){
    float a2, b2, c2;
    cout << "Enter a2, b2, c2: ";

    if ((a2 / b2) == 1){
        if (((c2 / b2) == 1) || ((c2 / b2) == -1)) cout << "inf solutions" << endl;
        else cout << "0 solutions" << endl;
    }
    else cout << "2 solutions";

    return 0;
}