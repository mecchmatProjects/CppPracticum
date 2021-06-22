#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int main(){
    vector<int> arr;
    int a;
    cin >> a;

    while (a != 0){
        arr.push_back(a);
        cin >> a;
    }

    double smallest = -INFINITY;

    for (int i = 0; i < arr.size(); i++){
        if(arr[i] < 0 && arr[i] > smallest) smallest = arr[i];
    }
    
    if (smallest != -INFINITY) cout << smallest;
    else{
        smallest = INFINITY;
        for (int i = 0; i < arr.size(); i++){
            if(arr[i] > 0 && arr[i] < smallest) smallest = arr[i];
        }
        cout << smallest;
    }
    

    return 0;
}