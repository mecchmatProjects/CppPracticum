#include <iostream>
using namespace std;


float func(float x, int k){
    if (k == 0) return 1;
    if (k == 1) return (-x / ((float) k));
    return (((-1) * x) / ((float) k)) * func(x, k - 1);
}

int main(){
    cout << "test: " << func(2, 3);

    return 0;
}