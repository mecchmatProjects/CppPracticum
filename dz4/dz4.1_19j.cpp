#include <iostream>
#include <math.h>
using namespace std;


float SoftExponential(float x, float alpha){
    if (alpha > 0) return  ((exp(alpha * x) - 1) / alpha) + alpha;
    else if (alpha == 0) return x;
    else return -log(1 - alpha * (alpha + x)) / alpha;
}

float derivative(float x, float alpha){
    if (alpha > 0) return exp(alpha * x);
    else return 1 / (1 - alpha * (alpha + x));
}


int main(){
    float x, alpha;
    cin >> x >> alpha;

    cout << "SoftExponential: " << SoftExponential(x, alpha) << endl;
    cout << "derivative: " << derivative(x, alpha) << endl; 

    return 0;
}