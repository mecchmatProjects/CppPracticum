#include <iostream>
#include <string>
#include <ctime>
#include <ctype.h>
using namespace std;

//перевірка на наявність числа
bool isNumber(const string& s);



int main() 
{
	
	string N;
	unsigned n(0);

	//зчитування
	while (!isNumber(N))
	{
		cout << "Size of array:\t";
		getline(cin, N);
	}
	n = (unsigned)stoi(N);
	
	//вирішення задачі
	int* arr = new int[n];
	cout << "Array:\n";
	srand((int)time(nullptr));
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = rand() % 50;
		cout << arr[i] << ' ';
	}
	cout << endl;
	//найменше, середнє та найбільше значення масивів та сума всіх значень для знаходждення середнього
	double min = arr[0];
	double max(min);
	double sum(0);
	//визначаємо їх обходячи масив

	for (size_t i = 0; i < n; i++)
	{
		sum += arr[i];
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	//середнє арифметичне елементів масиву
	double average = sum / n;
	cout << "Min value:\t" << min;
	cout << "\nAverage value:\t" << average;
	cout << "\nMax value:\t" << max;
	cout << "\n\n";
	//різниця між значеннями елементів масиву та перевіряючимись значеннями
	pair<double,int> minDelta(99999, arr[0]), averageDelta(99999, arr[0]), maxDelta(99999, arr[0]);
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] != min && abs(min - arr[i]) < minDelta.first)
		{
			minDelta.first = abs(min - arr[i]);
			minDelta.second = arr[i];
		}
		if (arr[i] != average && abs(average - arr[i]) < averageDelta.first)
		{
			averageDelta.first = abs(average - arr[i]);
			averageDelta.second = arr[i];
		}
		if (arr[i] != max && abs(max - arr[i]) < maxDelta.first)
		{
			maxDelta.first = abs(max - arr[i]);
			maxDelta.second = arr[i];
		}
	}
	cout << "Closest to min value:\t" << minDelta.second;
	cout << "\nClosest to average value:\t" << averageDelta.second;
	cout << "\nClosest to max value:\t" << maxDelta.second;
	cout << "\n\n";
	delete[]arr;
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