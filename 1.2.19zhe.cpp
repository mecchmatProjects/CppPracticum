#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <ctype.h>
using namespace std;

//перевірка на наявність числа
bool isNumber(const string& s);

//факторіал
int Factorial(int n)
{
	if (n <= 1) 
		return 1;
	
	return n * Factorial(n - 1);	//рекурсивний виклик
}
//піднесення до степеня
double Pow(int x, int n)
{
	if (n == 0) 
		return 1;
	if (n < 0)
	{
		x = 1 / x;
		n *= -1;
	}
	double result = x;
	for (size_t i = 1; i < n; i++)
		result *= x;
	return result;
}

double f(int x, int k)
{
	double result = 0;

	result = Pow(-1, k) * Pow(x, 2*k) / Factorial(2*k+1);

	return result;
}

int main() 
{
	
	string X, K;
	int x(0), k(0);

	//зчитування
	cout << "f(x, k) - ?";
	while (!isNumber(X) || !isNumber(K))
	{
		cout << "\nx = ";
		getline(cin, X);

		cout << "\n(k >= 0)\nk = ";
		getline(cin, K);
	}
	x = stoi(X);
	k = stoi(K);
	
	//вирішення задачі
	if (k < 0)
		exit(0);
	cout << "\nf(x, k) = " << f(x, k) << "\n\n";

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