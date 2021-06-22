#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>
using namespace std;

//функция проверки строки на число
bool isNumber(const std::string& s);

double f(int x, int y, unsigned n);


int main() 
{
	//задание 1.2.2г
	string X, Y, N;
	int x(0), y(0);
	unsigned n(0);

	cout << "Enter a dot:";
	while (!isNumber(X) || !isNumber(Y) || !isNumber(N))
	{
		cout << "\nx = ";
		getline(cin, X);

		cout << "y = ";
		getline(cin, Y);

		cout << "n = ";
		getline(cin, N);
	}
	x = stoi(X);
	y = stoi(Y);
	n = stoi(N);

	cout << "f(x, y, n) = " << f(x, y, n) << endl;

    return 0;
}


bool isNumber(const std::string& s)
{
	if (s.empty())
		return 0;

	size_t offset = 0;
	if (s[offset] == '-')
		++offset;
	return s.find_first_not_of("0123456789", offset) == std::string::npos;
}

double f(int x, int y, unsigned n)
{
	double result(1);

	for (size_t i = 1; i <= n; i++)
		result += (pow(x, pow(2, i)) * pow(y, i));

	return result;
}