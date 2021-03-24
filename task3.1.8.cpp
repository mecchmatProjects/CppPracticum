// task 3.1.8 
/*
Ввести натуральне число M. Поміняйте місцями біти її двійкового запису
з номерами i та j (що теж вводяться) та виведіть отримане число в десятковому
та шістнадцятковому вигляді.
*/

#include <iostream>
using namespace std;


int swapBits(unsigned int x, unsigned int p1,
             unsigned int p2)
{
    unsigned int set1 = (x >> p1) & ((1U << 1) - 1);
    unsigned int set2 = (x >> p2) & ((1U << 1) - 1);
    unsigned int Xor = (set1 ^ set2);

    Xor = (Xor << p1) | (Xor << p2);


    unsigned int result = x ^ Xor;

    return result;
}

int main()
{
    int res = swapBits(5, 0, 1);
    cout << "Result = " << dec << res << endl;
    cout << "Result = " << hex << res << endl;

    return 0;
}
