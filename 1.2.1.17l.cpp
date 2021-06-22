#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>
using namespace std;

//перевірка на наявність числа
bool isNumber(const string& s);

double y(double x, double eps)
{
	if (abs(x) >= 1)		//за умовою х знаходиться в межах одиниці
		exit(0);
	double result = 1;
	double delta = 999;
	double iteration = 1;
	while (abs(delta) >= eps)
	{
		delta = pow(-1, iteration) * pow(x, 2* iteration);
		result += delta;
		iteration++;
	}
	return result;
}

int main() 
{
	
	string X;
	double x(0);
	double eps = 0.00001;		//точність обчислень

	//зчитування
	cout << "(|x| < 1)\nx = ";
	cin >> x;
	
	//вирішення прикладу
	cout << "y = " << y(x, eps) << endl;
	
    return 0;
}


bool isNumber(const string& s)
{
	if (s.empty())
		return 0;

	size_t offset = 0;
	if (s[offset] == '-')
		++offset;
	return s.find_first_not_of("0123456789", offset) == string::npos;
}