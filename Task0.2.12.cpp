

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a;
	int b;
	int c;
	float x1;
	float x2;
	cout << "Enter a:";
	cin >> a;
	cout << "Enter b:";
	cin >> b;
	cout << "Enter c:";
	cin >> c;
	if ((b * b - 4 * a * c) >= 0)
	{
		x1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
		cout << "x_1 = " << x1<<endl;
		x2 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
		cout << "x_2 = " << x2;

	}
	else
	{
		cout << "no x";
	}

}

