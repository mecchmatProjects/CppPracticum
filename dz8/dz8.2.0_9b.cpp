#include <iostream>
#include <cmath>
using namespace std;


int main(){
    cout << "Enter N: ";
    unsigned int n = 0;
    cin >> n;

    int *array = new int[n];

    for(int i = 0; i < n; ++i){
        int val = 0;
        cin >> val;
        array[i] = val;
    }

    unsigned int counter = 0;

    for(int i = 0; i < n; ++i){
        if (array[i] % 2 == 0 && floor(pow(array[i], (1.0/3))) == pow(array[i], (1.0/3))){
            counter++;
        }
    }

    cout << "Amount: " << counter;


    delete[] array;
    return 0;
}