#include <math.h>
#include <iostream>
#include <cmath>
#include <stdio.h>
//#include <locale>
using namespace std;
class point
{
public:
    double x;
    double y;
    double result() {
        double res;
        res=sqrt(x*x+y*y);
        return res;
    }
    double return_x(){
        return x;
    }
    double return_y(){
        return y;
    }
    double  operation(const point& other)
    {
        double dx=x-other.x;
        double dy=y-other.y;
        return sqrt(dx*dx+dy*dy);
    }
};

int main()
{
    setlocale(LC_ALL,"Russian");
    point tochka2;
    double kl=0;
    cout<<"x=";
    cin>>tochka2.x;
    cout<<endl;
    cout<<"y=";
    cin>>tochka2.y;
    cout<<endl;
    cout <<"tochka1:"<<tochka2.result()<<endl;
    while(true)
    {

        point tochka1;
        tochka1.x=tochka2.x;
        tochka1.y=tochka2.y;
        point tochka2;
        cout<<"x2=";
        cin>>tochka2.x;
        if(cin.get()!=(double)'\n')
        {
            cout<<"Perimetr last = "<<kl<<endl;
            break;
        }
        cout<<endl;
        cout<<"y2=";
        cin>>tochka2.y;
        if(cin.get()!=(double)'\n')
        {
            cout<<"Perimetr last = "<<kl<<endl;
            break;
        }
        cout<<endl;
        cout <<"tochka2:"<<tochka2.result()<<endl;
        cout <<"rasstoyanue:"<<tochka1.operation(tochka2)<<endl;
        kl+=tochka1.operation(tochka2);
        cout<<"Perimetr now = "<<kl<<endl;
    }


    return 0;
}
