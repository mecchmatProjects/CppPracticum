#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double k;
    cout<<"Необхідно ввести натуральне число:";
    cin>>k;
    double xk =1/k;
    double x;
    cout<<"Необхідно ввести значення x:";
    cin>>x;
    
    for(double i=1;i<k+1;i++){
        xk=xk*(-1)*x;

    }
    cout<<"x(k): "<<xk<<endl;

    return 0;
}
