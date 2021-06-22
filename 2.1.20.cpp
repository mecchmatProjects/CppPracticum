#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <ctype.h>
using namespace std;

//функция проверки строки на число
bool isNumber(const string& s);

int main() 
{
	//задание 2.1.20
	string N, M;
	unsigned n(0), m(0);

	//считывание
	cout << "Matrix sizes:\n";
	while (!isNumber(N) || !isNumber(M))
	{
		cout << "n = ";
		getline(cin, N);

		cout << "m = ";
		getline(cin, M);
	}
	n = (unsigned)stoi(N);
	m = (unsigned)stoi(M);
	
	//решение задачи
	int** arr = new int* [n];
	srand((int)time(nullptr));
	//заполнение и вывод матрицы n*m
	cout << endl;
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = new int[m];
		for (size_t j = 0; j < m; j++)
		{
			arr[i][j] = -rand() % 10;
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
	//индексы рядков с исключительно отрицательными значениями
	int firstNegative(-1), lastNegative(-1);
	for (size_t i = 0; i < n; i++)
	{
		//флаг того что рядок полностью отрицателен
		bool ok = true;
		for (size_t j = 0; j < n; j++)
		{
			if (arr[i][j] >= 0)
				ok = false;
		}
		if (firstNegative == -1 && ok)		//если еще не был найден первый рядок с исключительно отрицательными значениями 
		{
			firstNegative = i;
			lastNegative = i;
		}
		else if(ok)
			lastNegative = i;
	}
	if (firstNegative != lastNegative)		//если эти рядки не совпали, то их нужно поменять
	{
		int temp(0);	//временная переменная для обмена данными
		for (size_t j = 0; j < m; j++)
		{
			temp = arr[firstNegative][j];
			arr[firstNegative][j] = arr[lastNegative][j];
			arr[lastNegative][j] = temp;
		}
	}
	
	//вывод измененной матрицы - смотрим, что получилось
	cout << endl;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "\nSwapped " << firstNegative+1 << " and " << lastNegative + 1 << " rows.\n\n";

	//очищение памяти выделенной под матрицу
	for (size_t i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
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