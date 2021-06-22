#pragma once
#include "ComplexNumber.h"
#include <string>
#include <vector>
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;


class ComplexPoly
{
private:
	vector <double> coefficients;		//список коеф≥ц≥Їнт≥в комплексних чисел ComplexNumber = z = x + yi  (реальна частина + у€вна частина)
	int degree;
public:
	ComplexPoly();
	ComplexPoly(int _degree, vector <double> coefs);
	ComplexPoly(int _degree);
	
	friend ostream& operator<<(ostream& out, const ComplexPoly& p);
	void operator ()(const ComplexPoly& other);

	ComplexPoly operator +(const ComplexPoly& other);
	ComplexPoly operator -(const ComplexPoly& other);
	ComplexPoly operator /(const ComplexPoly& other);
	ComplexPoly operator *(const ComplexPoly& other);

	ComplexPoly operator +(double x);
	ComplexPoly operator -(double x);
	ComplexPoly operator /(double x);
	ComplexPoly operator *(double x);

	ComplexPoly operator %(ComplexPoly& other);

	ComplexNumber Value(ComplexNumber z);
	ComplexPoly Derivative();
	string Polynom();
	void clear();
	void generate(unsigned n);
	void input_by_string();
	void input_by_space();
	void writePolynomToFile();
};