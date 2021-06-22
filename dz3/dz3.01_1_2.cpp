#include <iostream>
using namespace std;

float biggest(float a, float b, float c){
    if (a > c){
        if (b > a) return b;
        else return a;
    }
    else {
        if (b > c) return b;
        else return c;
    }
}

float lowest(float a, float b, float c){
    if (a < c){
        if (b < a) return b;
        else return a;
    }
    else {
        if (b < c) return b;
        else return c;
    }
}


int main(){
    float a, b, c;
    cin >> a >> b >> c;

    cout << "Biggest: " << biggest(a, b, c) << endl;
    cout << "Lowest: " << lowest(a, b, c) << endl;

    return 0;
}