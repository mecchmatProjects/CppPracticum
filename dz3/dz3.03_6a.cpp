#include <iostream>
#include <math.h>
using namespace std;


double func(double x){
    return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}

double derivative(double x){
    return 1 / pow((exp(x) + exp(-x)) / 2, 2);
}


int main(){
    double x = 228.322;
    cout << "func: " << func(x) << endl;
    cout << "derivative: " << derivative(x) << endl; 


    return 0;
}