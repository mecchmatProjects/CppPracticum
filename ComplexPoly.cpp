#include "ComplexPoly.h"
#include "ComplexNumber.h"
#include <string>
#include <vector>
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

ComplexPoly::ComplexPoly()
{
	coefficients.clear();
	degree = -1;
}
ComplexPoly::ComplexPoly(int _degree, vector <double> coefs) : degree(_degree), coefficients(coefs)
{}
ComplexPoly::ComplexPoly(int _degree) : degree(_degree), coefficients(_degree + 1, 0)
{}

ostream& operator<<(ostream& out, const ComplexPoly& p)
{
	string polynom = "ComplexPoly(z) = ";

	for (int i = p.degree - 1; i > 0; i--)
	{
		polynom += (to_string(p.coefficients.at(i)) + "*" + "z^" + to_string(i) + " + ");
	}
	polynom += to_string(p.coefficients.at(0));

	out << polynom;

	return out;
}
void ComplexPoly::operator ()(const ComplexPoly& other)
{
	this->degree = other.degree;
	this->coefficients = other.coefficients;
}

ComplexPoly ComplexPoly::operator +(const ComplexPoly& other)
{
	int dgr;
	if (this->degree > other.degree)
		dgr = this->degree;
	else
		dgr = other.degree;
	vector<double> coefs(dgr, 0);

	for (int i = 0; i < this->degree; i++)
	{
		coefs.at(i) += this->coefficients.at(i);
	}
	for (int i = 0; i < other.degree; i++)
	{
		coefs.at(i) += other.coefficients.at(i);
	}

	ComplexPoly result(dgr, coefs);

	return result;
}
ComplexPoly ComplexPoly::operator -(const ComplexPoly& other)
{
	int dgr;
	if (this->degree > other.degree)
		dgr = this->degree;
	else
		dgr = other.degree;
	vector<double> coefs(dgr, 0);

	for (int i = 0; i < this->degree; i++)
	{
		coefs.at(i) += this->coefficients.at(i);
	}
	for (int i = 0; i < other.degree; i++)
	{
		coefs.at(i) -= other.coefficients.at(i);
	}

	ComplexPoly result(dgr, coefs);

	return result;
}
ComplexPoly ComplexPoly::operator /(const ComplexPoly& other)
{
	bool inAlgoritm = true;

	ComplexPoly temp(degree - other.degree);
	ComplexPoly ob_1(this->degree, this->coefficients);
	ComplexPoly ob_2(other.degree, other.coefficients);
	ComplexPoly ob_4(this->degree + 1, this->coefficients);


	double mnojnik;
	int k = 0;
	int i, j;
	while (inAlgoritm)
	{
		ob_4.coefficients = other.coefficients;

		if (ob_2.degree < ob_1.degree)
		{
			for (i = ob_1.degree - 2, j = ob_2.degree - 2; i >= 0, j >= 0; i--, j--)
				if (j < 0)
					ob_4.coefficients.at(i) = 0;
				else
					ob_4.coefficients.at(i) = ob_2.coefficients.at(j);
		}

		mnojnik = ob_1.coefficients[ob_1.degree - 2] / ob_4.coefficients[ob_1.degree - 2];

		if (temp.degree - k - 1 < 0)
			break;

		temp.coefficients[temp.degree - k - 1] = mnojnik;
		k++;

		for (int i = 0; i <= ob_1.degree - 2; i++)
			ob_4.coefficients.at(i) *= mnojnik;

		for (int i = 0; i <= ob_1.degree - 2; i++)
			ob_1.coefficients.at(i) -= ob_4.coefficients.at(i);

		ob_1.degree--;
		if (ob_2.degree > ob_1.degree) inAlgoritm = false;
	}

	return temp;

}
ComplexPoly ComplexPoly::operator %(ComplexPoly& other)		//оператор перевантаження остачі від ділення многочленів
{
	bool inAlgoritm = true;

	ComplexPoly ob_1(this->degree, this->coefficients);
	ComplexPoly ob_2(other.degree, other.coefficients);
	ComplexPoly ob_4(this->degree + 1, this->coefficients);

	double mnojnik;
	int i, j;
	while (inAlgoritm)
	{
		ob_4.coefficients = other.coefficients;

		if (ob_2.degree < ob_1.degree)
		{
			for (i = ob_1.degree - 2, j = ob_2.degree - 2; i >= 0, j >= 0; i--, j--)
				if (j < 0)
					ob_4.coefficients.at(i) = 0;
				else
					ob_4.coefficients.at(i) = ob_2.coefficients.at(j);
		}

		if ((unsigned)(ob_1.degree - 1) > ob_4.coefficients.size() - 1)
			break;
		mnojnik = ob_1.coefficients[ob_1.degree - 1] / ob_4.coefficients[ob_1.degree - 1];

		for (int i = 0; i <= ob_1.degree - 1; i++)
			ob_4.coefficients[i] *= mnojnik;

		for (int i = 0; i <= ob_1.degree - 1; i++)
			ob_1.coefficients[i] -= ob_4.coefficients[i];

		ob_1.degree--;
		if (ob_2.degree > ob_1.degree) inAlgoritm = false;
	}

	return ob_1;
}

ComplexPoly ComplexPoly::operator +(double x)
{
	ComplexPoly result(this->degree, this->coefficients);

	if (this->degree > -1)
		result.coefficients.at(0) += x;
	else
	{
		result.degree = 0;
		result.coefficients.at(0) = x;
	}

	return result;
}
ComplexPoly ComplexPoly::operator -(double x)
{
	ComplexPoly result(this->degree, this->coefficients);

	if (this->degree > -1)
		result.coefficients.at(0) -= x;
	else
	{
		result.degree = 0;
		result.coefficients.at(0) = -x;
	}

	return result;
}
ComplexPoly ComplexPoly::operator /(double x)
{
	ComplexPoly result(this->degree, this->coefficients);

	for (int i = 0; i < degree; i++)
	{
		result.coefficients.at(i) /= x;
	}

	return result;
}
ComplexPoly ComplexPoly::operator *(double x)
{
	ComplexPoly result(this->degree, this->coefficients);

	for (int i = 0; i < degree; i++)
	{
		result.coefficients.at(i) *= x;
	}

	return result;
}

ComplexNumber ComplexPoly::Value(ComplexNumber z)
{
	ComplexNumber result;

	for (int i = 0; i < degree; i++)
	{
		result.x += coefficients.at(i) * pow(z.x, i);
		result.y += coefficients.at(i) * pow(z.y, i);
	}

	return result;
}
ComplexPoly ComplexPoly::Derivative()
{
	ComplexPoly result(degree - 1);

	for (int i = 0; i < degree - 1; i++)
	{
		result.coefficients.at(i) = this->coefficients.at(i + 1) * (i + 1);
	}

	return result;
}
string ComplexPoly::Polynom()
{
	string polynom = "ComplexPoly(z) = ";

	for (int i = this->degree - 1; i > 0; i--)
	{
		polynom += (to_string(this->coefficients.at(i)) + "*" + "z^" + to_string(i));
	}
	polynom += to_string(this->coefficients.at(0));

	return polynom;
}
void ComplexPoly::clear()
{
	this->degree = -1;
	this->coefficients.clear();
}
void ComplexPoly::generate(unsigned n)
{
	clear();
	this->degree = n;
	vector <double> new_coefs(n, 0);
	this->coefficients = new_coefs;
	srand(static_cast<int>(time(NULL)));
	for (unsigned i = 0; i < n; i++)
	{
		coefficients.at(i) = rand() % 50;
	}
}
void ComplexPoly::input_by_string()		//введення поліному формату 'ComplexPoly(z) = 2z^3-1z^2+0z^1+5'
{
	string p;
	cout << "ComplexPoly(z) = ";
	getline(cin, p);

	int degree(1);

	for (size_t i = 0; i < p.size(); i++)
		if (p.at(i) == '^')
			degree++;

	vector<double> coefs(degree + 1, 0);

	string coef = "";
	bool sign = 1;
	int coef_number = degree;
	try
	{
		for (size_t i = 0; i < p.size(); i++)
		{
			if (p.at(i) != 'z')
				coef += p.at(i);
			else if (p.at(i) == '^')
			{
				double c = stoi(coef);
				if (sign == 1)
					coefs.at(coef_number) = c;
				else
					coefs.at(coef_number) = -c;
				coef_number--;
				coef.clear();
			}
			else if (i > 0)
				if (p.at(i - 1) == '^')
					if (p.at(i + 1) == '+')
						sign = 1;
					else
						sign = 0;
				else
					continue;
		}
		if (coef_number != 0)
			throw exception("Exception caugt: 'Bad input format'");
	}
	catch (exception e)
	{
		system("cls");
		cout << e.what() << endl << endl;
		exit(0);
	}
	this->degree = degree;
	this->coefficients = coefs;
}
void ComplexPoly::input_by_space()		//введення коефіцієнтів через пробіл
{
	string str;
	cout << "Coefficients (separated by space):\t";
	getline(cin, str);
	int dgr(0);
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str.at(i) == ' ')
			++dgr;
	}
	++dgr;
	string coef = "";
	vector<double>coefs;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str.at(i) == ' ')
		{
			double c = stoi(coef);
			coefs.insert(coefs.begin(), c);

			coef.clear();
		}
		else
			coef += str.at(i);
	}
	double c = stoi(coef);
	coefs.insert(coefs.begin(), c);
	coef.clear();

	this->degree = dgr;
	this->coefficients = coefs;
}
void ComplexPoly::writePolynomToFile()
{
	string path;
	cout << "File name (example.txt):\t";
	cin.ignore();
	cin.clear();
	getline(cin, path);

	ofstream fout(path, ios_base::out | ios_base::trunc);
	fout << Polynom();

	fout.close();
}