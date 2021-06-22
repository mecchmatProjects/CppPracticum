#include <iostream>

#include <math.h>

#include <stdio.h>

namespace functions {
    using namespace std;

    double function(double x)

    {
        double res = exp(-x * x);
        return res;
    }

    double derivative(double x)

    {
        double res = function(x) * (-2 * x);
        return res;
    }

}

int main()

{   
    using namespace std;
    
    double x = 0;
   
    cout << "Input number: ";

    cin >> x;

    cout << functions::function(x) << endl << functions::derivative(x) << endl;

    return 0;
}
