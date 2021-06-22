#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

class Triangle
{
private:
    int a;
    int b;
    float c;
    int angle;

public:
    void readTriangle();
    float getArea(void);
    float getPerimeter(void);
    void getSide();
};

void Triangle::readTriangle()
{
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    cout<<"Enter angle: ";
    cin>>angle;
}


void Triangle::getSide()
{
    c = sqrt(a*a+b*b-2*b*a*cos(angle));
}

float Triangle::getPerimeter(void)
{
   return (a+b+c);
}

float Triangle::getArea(void)
{
    return (0.5*a*b*sin(angle));
}


int main()
{
    Triangle tr;
    tr.readTriangle();
    tr.getSide();
    cout << tr.getPerimeter() << endl;
    cout << tr.getArea() << endl;

    return 0;
}
