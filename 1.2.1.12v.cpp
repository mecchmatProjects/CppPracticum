#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

//перевірка на наявність числа
bool isNumber(const string& s);

//рекурсивна ф-ція
double v(int i)
{
	if (i == 0 || i == 1)  
		return 0;
	if (i == 2)
		return 1.5;
	else
		return ((i-2)/(pow(i-3, 2) + 1)*v(i-1) - v(i-2)*v(i-3) + 1);
}

int main() 
{
	
	string X;
	int x(0);

	//зчитування
	while (!isNumber(X))
	{
		cout << "i = ";
		getline(cin, X);
	}
	x = stoi(X);
	
	//вирішення прикладу
	cout << "\nv(i) = " << v(x) << "\n\n";

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