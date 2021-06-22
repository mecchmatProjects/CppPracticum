#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>
using namespace std;

//перевірка на наявність числа
bool isNumber(const string& s);

double a(int i)
{
	if (i == 0)
		return 0;
	if (i == 1)
		return 1;
	return (a(i-1) + i*a(i-2));
}

double sum(int n)
{
	double result = 0;

	for (int i = 1; i <= n; i++)
		result += pow(2, i) * a(i);

	return result;
}

int main() 
{
	
	string X;
	int n(0);

	//зчитування
	cout << "S(n) - ?\n";
	while (!isNumber(X))
	{
		cout << "n = ";
		getline(cin, X);
	}
	n = stoi(X);
	
	//вирішення прикладу
	cout << "\nx(n) = " << sum(n) << "\n\n";

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