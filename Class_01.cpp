// Class_01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>

using namespace std;

float pr(float x1, float y1, float x2, float y2, float x3, float y3 )
{
    float d1 = pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5);
    float d2 = pow((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3), 0.5);
    float d3 = pow((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3), 0.5);
    float p2 = (d1 + d2 + d3) / 2;
    y = pow(p2 * (p2 - d1) * (p2 - d2) * (p2 - d3), 0.5);
    return y;
}


int main()
{
    float x1, y1, x2, y2, x3, y3;
    cin >> x1,y1 ;
    cin >> x2, y2;
    cin >> x3, y3;
    y = pr(x1, y1, x2, y2, x3, y3);
    cout << y << endl;
}