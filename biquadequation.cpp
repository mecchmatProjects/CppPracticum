#include <iostream>
#include <cmath>
#include <cfloat>
#include <cstdbool>

using namespace std;

bool isNearlyZero(double x)
{
	return (fabs(x) < 2 * DBL_EPSILON);
}

bool isNearlyEqual(double x, double y)
{
	return (fabs(x - y) < 2 * DBL_EPSILON);
}

void quadEquation(double a, double b, double c)
{
	if (isNearlyZero(a))
	{
		if (isNearlyZero(b))
		{
			if (isNearlyZero(c)) {cout << "Infinity of solutions" << endl;}
			else { cout << "No solutions" << endl; }
		}
		else
		{
			double x = -c / b;
			if (x > 0)
			{
				double x_res = sqrt(x);
				cout << "x1 = " << x_res << endl;
				cout << "x2 = " << -x_res << endl;
			}
			else if (isNearlyZero(x))
			{
				cout << "x = " << 0 << endl;
			}
			else
			{
				cout << "No solutions" << endl;
			}
		}
	}
	else
	{
		double D = b * b - 4 * a * c;
		cout << "D = " << D << endl;
		if (isNearlyZero(D))
		{
			double result1 = -b / (2 * a);
			cout << "result1 = " << result1 << endl;

			if (result1 > 0)
			{
				double x_res_D = sqrt(result1);

				cout << "x1 = " << x_res_D << endl;
				cout << "x2 = " << -x_res_D << endl;
			}
			else if (isNearlyZero(result1))
			{
				cout << "x = " << 0 << endl;
			}
			else { cout << "No solutions" << endl; }
		}
		else if (D>0)
		{
			double x1 = (-b + sqrt(D)) / (2 * a);
			double x2 = (-b - sqrt(D)) / (2 * a);
			cout << "X1 = " << x1 << endl;
			cout << "X2 = " << x2 << endl;

			if (x1 >= 0 && x2 >= 0)
			{
				cout << "x1 = " << sqrt(x1) << endl;
				cout << "x2 = " << -sqrt(x1) << endl;
				cout << "x3 = " << sqrt(x2) << endl;
				cout << "x4 = " << -sqrt(x2) << endl;
			}
			else if (x1 >= 0 && x2 < 0)
			{
				cout << "x1 = " << sqrt(x1) << endl;
				cout << "x2 = " << -sqrt(x1) << endl;
			}
			else if (x1 < 0 && x2 >= 0)
			{
				cout << "x1 = " << sqrt(x2) << endl;
				cout << "x2 = " << -sqrt(x2) << endl;
			}
			else if (x1 < 0 && x2 < 0)
			{
				cout << "No real solutions" << endl;
			}
		}
		else { cout << "No real solutions" << endl; }
	}
}

int main()
{
	double a, b, c;
	cout << "Input coefficients of equation: ";
	cin >> a >> b >> c;

	quadEquation(a, b, c);
}
