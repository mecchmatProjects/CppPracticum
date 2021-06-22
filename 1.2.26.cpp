#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <ctype.h>
using namespace std;

//перевірка на наявність числа
bool isNumber(const std::string& s);

string fractionToDecimal(int numr, int denr);

int main() 
{
	
	string N, M;
	int n(0), m(0);

	//зчитувананя
	cout << "n/m - ?";
	while (!isNumber(N) || !isNumber(M))
	{
		cout << "\nn = ";
		getline(cin, N);

		cout << "m = ";
		getline(cin, M);
	}
	n = stoi(N);
	m = stoi(M);
	
	//вирішення задачі
	if (m == 0)
		exit(0);						//не ділити на нуль
	
	string res = fractionToDecimal(n, m);
	if (res == "")
		cout << "No period for this fraction";
	else
		cout << "\nPeriod is (" << res << ")\n\n";

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

string fractionToDecimal(int numr, int denr)
{
	string res;			//результат (період)

	map<int, int> mp;	//місце зберігання остачі від ділення
	mp.clear();

	int rem = numr % denr;		//перша остача

	//продовжуємо шукати остачі поки одна з них не зрівняється з нулем чи не повториться
	while ((rem != 0) && (mp.find(rem) == mp.end()))
	{
		//зберігаємо поточну остачу
		mp[rem] = res.length();

		//множимо на 10 - крок алгоритму ділення в стовпчик
		rem = rem * 10;

		//рахуємо дріб
		int res_part = rem / denr;
		res += to_string(res_part);

		//оновлюємо остачу від ділення
		rem = rem % denr;
	}

	//якщо остача рівна 0 - періоду не існує, інакше - повертаємо
	return (rem == 0) ? "" : res.substr(mp[rem]);
}