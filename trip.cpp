#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;


struct Passenger
{
	string name, departmentCity, arrivalCity;
	double money;		//количество денег на счету

	Passenger() : name(""), departmentCity(""), arrivalCity(""), money(0) {}
	Passenger(string n, string d, string a, double m)
	{
		if (m < 0)
		{
			invalid_argument e("Balance is less than zero.");
			throw exception(e);
		}
		money = m;
		name = n;
		departmentCity = d;
		arrivalCity = a;
	}
	void input()		//метод введення
	{
		string n, d, a, m;
		double _money;
		cin.clear();
		cin.ignore();

		cout << "Name:\t";
		getline(cin, n);

		cout << "Department city:\t";
		getline(cin, d);

		cout << "Arrival city:\t";
		getline(cin, a);

		cout << "Balance:\t";
		getline(cin, m);
		_money = stod(m);

		name = n;
		departmentCity = d;
		arrivalCity = a;
		money = _money;
	}
	void show()		//метод виведення
	{
		cout << name << ", from " << departmentCity << " to " << arrivalCity << "; " << money << "grn." << endl;
	}
	bool pay(double summ)
	{
		if (summ < 0)
		{
			invalid_argument e("Summ is less than zero.");
			throw exception(e);
		}
		if (money - summ < 0)		//если недостаточно денег на счету для оплаты
		{
			return 0;
		}
		else
		{
			money -= summ;
			return 1;
		}
	}
};

struct Marshrute
{
	string departmentCity, arrivalCity;
	unsigned distance;

	Marshrute() : departmentCity(""), arrivalCity(""), distance(0) {}
	Marshrute(string _from, string _to, unsigned _distance)
	{
		if (_distance < 0)
		{
			invalid_argument e("Cost is less than zero.");
			throw exception(e);
		}
		distance = _distance;
		departmentCity = _from;
		arrivalCity = _to;
	}
};

int main()
{
	double costPerKM = 1.5;		//стоимость за километр пути
	
	vector<Marshrute> marshrutes;
	Marshrute m1("Kiev", "Moscow", 640);
	Marshrute m2("Kiev", "Praga", 1970);
	Marshrute m3("Kiev", "New York", 17900);
	Marshrute m4("Kiev", "Barcelona", 5400);
	Marshrute m5("Kiev", "Berlin", 3600);
	marshrutes.push_back(m1);
	marshrutes.push_back(m2);
	marshrutes.push_back(m3);
	marshrutes.push_back(m4);
	marshrutes.push_back(m5);

	unsigned n;
	cout << "Enter amount of passengers:\t";
	cin >> n;
	vector<Passenger> passengers(n);

	cout << "\nAvailable marshrutes:\n";
	for (size_t i = 0; i < marshrutes.size(); i++)
	{
		cout << i + 1 << ". " << marshrutes[i].departmentCity << " - " << marshrutes[i].arrivalCity << " \t(" << marshrutes[i].distance << " km)" << endl;
	}

	for (size_t i = 0; i < n; i++)
	{
		Passenger p;
		cout << endl;
		p.input();
		passengers[i] = p;
	}
	cout << "\nEntered passengers:\n";
	for (size_t i = 0; i < passengers.size(); i++)
	{
		cout << i + 1 << ". ";
		passengers[i].show();
	}
	//оплата билетов
	cout << "\n\nTickets paying:\n\n";
	for (size_t i = 0; i < passengers.size(); i++)
	{
		int found = -1;		//существует ли такой маршрут (если не -1, то найдется его индекс, иначе маршрута не существует)
		for (size_t j = 0; j < marshrutes.size(); j++)
		{
			if ((marshrutes[j].departmentCity == passengers[i].departmentCity && marshrutes[j].arrivalCity == passengers[i].arrivalCity) ||
				(marshrutes[j].arrivalCity == passengers[i].departmentCity && marshrutes[j].departmentCity == passengers[i].arrivalCity))
				found = j;
		}
		if (found == -1)
		{
			cout << "Marshrutes for passenger " << passengers[i].name << " dont found.\n";
			continue;
		}
		else
		{
			cout << "Passenger " << passengers[i].name << ", marhsrute is: (" << passengers[i].arrivalCity << " - " << passengers[i].departmentCity << "). ";
			cout << "Distance is " << marshrutes[found].distance << ", cost is " << marshrutes[found].distance * costPerKM << ". Trying to get money from balance...\n";
			if (passengers[i].pay(marshrutes[found].distance * costPerKM))
			{
				cout << "Ticket bought succesfully! Current passenger balance is " << passengers[i].money << "\n\n";
			}
			else
			{
				cout << "Cannot buy the ticket - not enough money on balance (" << passengers[i].money << ")" << "\n\n";
			}
		}
	}

	return 0;
}