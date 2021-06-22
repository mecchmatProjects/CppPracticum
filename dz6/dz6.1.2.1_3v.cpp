#include <iostream>
using namespace std;


int factorial(unsigned int n){
    if (n == 0 || n == 1) return 1;
    else return n * factorial(n - 1);
} 


float func(unsigned int n){
    if (n == 0) return 1;
    else return (1 / ((float) factorial(n + 1))) * func(n - 1);
}

int main(){
    cout << func(3);
    return 0;
}