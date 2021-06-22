#include <iostream>
using namespace std;


int main(){
    unsigned int x;
    unsigned int counter = 0, sum = 0;
    float reverse_sum = 0;
    cout << "Enter x: ";
    cin >> x;


    while (x != 0){
        sum += x;
        reverse_sum += (1 / (float) x);
        counter++;
        cout << sum << " " << reverse_sum << " " << counter << endl;
        cout << "Enter x: ";
        cin >> x;
    }

    cout << "Seredne arifmetichne: " << ((float) sum) / counter << endl;
    cout << "Seredne garmonichne: " << ((float) counter) / reverse_sum;
    

    return 0;
}