#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>
using namespace std;

//функция проверки строки на число
bool isNumber(const std::string& s)
{
	if (s.empty())
		return 0;

	size_t offset = 0;
	if (s[offset] == '-')
		++offset;
	return s.find_first_not_of("0123456789", offset) == std::string::npos;
}

int main() 
{
	//задание 1.1.17
	string X, Y, Z, R;
	double x(0), y(0), z(0);
	int radius(0);

	cout << "Enter a dot:";
	while (!isNumber(X) || !isNumber(Y) || !isNumber(Z) || !isNumber(R))
	{
		cout << "\nx = ";
		getline(cin, X);

		cout << "y = ";
		getline(cin, Y);

		cout << "z = ";
		getline(cin, Z);

		cout << "Sphere radius: ";
		getline(cin, R);
	}
	x = stoi(X);
	y = stoi(Y);
	z = stoi(Z);
	radius = stoi(R);

	//если расстояние от центра координат к точке меньше чем заданный радиус сферы, условие выполняется
	if (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) <= radius)
		cout << "\nEntered dot is inside the sphere\n";
	else
		cout << "\nEntered dot is NOT inside the sphere\n";

    return 0;
}