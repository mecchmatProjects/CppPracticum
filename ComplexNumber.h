#pragma once
#include <iostream>

struct ComplexNumber
{
	double x, y;

	ComplexNumber() : x(0), y(0)
	{}
	ComplexNumber(double _x, double _y) : x(_x), y(_y)
	{}

	friend std::ostream& operator <<(std::ostream& out, const ComplexNumber& p);
	void operator ()(double _x, double _y);

	ComplexNumber operator *(const ComplexNumber& other);
	ComplexNumber operator /(const ComplexNumber& other);
	ComplexNumber operator +(const ComplexNumber& other);
	ComplexNumber operator -(const ComplexNumber& other);
};