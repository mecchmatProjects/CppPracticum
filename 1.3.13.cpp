#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

//перевірка на наявність числа
bool isNumber(const string& s);

//число в двійковому форматі в правильній послідовності
void forvardBinary(int n)
{
	if (n == 0)  
		return;
	forvardBinary(n / 2); 
	cout << n % 2;
}

int main() 
{
	
	string X;
	int x(0);

	//зчитування
	while (!isNumber(X))
	{
		cout << "x = ";
		getline(cin, X);
	}
	x = stoi(X);
	
	//вирішення задачі
	int i = 0;
	while (i < sizeof(int) * 8)			//інвертування бітів даного числа
	{
		x = x ^ (1 << i);
		++i;
	}

	cout << "Normal number representation:\t" << x << endl;
	cout << "Binary number representation:\t";
	forvardBinary(abs(x));
	cout << endl;

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