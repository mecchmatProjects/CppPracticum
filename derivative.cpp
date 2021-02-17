#include <iostream>
#include <cmath>

using namespace std;

bool isNearlyZero(double x)
{
	return (fabs(x) < 2 * DBL_EPSILON);
}

double isReLu_derivative(double x, double a)
{
	if (x < 0)
	{
		double res = ((-a) * x * x) / pow((1. + a * x * x), 1.5) + 1. / sqrt(1. + a * x * x);
		return res;
	}
	else if (isNearlyZero(x)) 
	{  
		double res = 0;
		return res;
	}
	else 
	{ 
		double res = 1;
		return res;
	}	
}

int main()
{
	double x, a;
	cout << "x = ";
	cin >> x;
	cout << "a = ";
	cin >> a;

	cout << "Result = " << fixed << isReLu_derivative(x, a);
}
