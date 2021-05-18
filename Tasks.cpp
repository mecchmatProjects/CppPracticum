#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    double x;
    int b;
    double c;
    int d;
    int k;
    double f;
    cout << "Enter x: ";
    cin >> x;
    b = (int) x;
    cout << "int:"<< b<< endl;
    c = modf(x,&f);
    cout << "fraction :" << c<< endl;
    d = b + 1;
    cout << "biggest int:"<< d <<endl;
    k = b - 1;
    cout << "smaller"<< k <<endl;




}


