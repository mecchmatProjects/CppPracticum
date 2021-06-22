#include <iostream>
using namespace std;


const int SIZE = 5;

float Hermit(int n, float val){
    if(n == 0){
        return 1;
    }
    else if(n == 1){
        return 2 * val;
    }
    else{
        return (2 * Hermit(n-1, val) - 2 * (n - 1) * Hermit(n-2, val)); 
    }
    
}


int main(){
    cout << "Enter value: ";
    float value = 0;
    cin >> value;

    float array[SIZE];

    for(int i = 0; i < SIZE; ++i){
        array[i] = Hermit(i, value);
    }

    for(int i =0; i < SIZE; ++i){
        cout << array[i] << " ";
    }
    return 0;
}