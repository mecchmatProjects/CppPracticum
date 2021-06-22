#include "ComplexNumber.h"
#include <string>
#include <cmath>
using namespace std;

ostream& operator<<(ostream& out, const ComplexNumber& p)
{
	string number;

	if (p.y > 0)
		number = ("z = " + to_string(p.x) + " + " + to_string(p.y) + "*i");
	else if (p.y < 0)
		number = ("z = " + to_string(p.x) + " - " + to_string(abs(p.y)) + "*i");
	else
		number = ("z = " + to_string(p.x));

	out << number;
	return out;
}
void ComplexNumber::operator ()(double _x, double _y)
{
	x = _x;
	y = _y;
}

ComplexNumber ComplexNumber::operator *(const ComplexNumber& other)
{
	ComplexNumber result;

	result.x = this->x * other.x - this->y * other.y;
	result.y = this->x * other.y + this->y * other.x;

	return result;
}
ComplexNumber ComplexNumber::operator /(const ComplexNumber& other)
{
	ComplexNumber result;

	result.x = (this->x * other.x + this->y * other.y) / (pow(other.x, 2) + pow(other.y, 2));
	result.y = (this->y * other.x - this->x * other.y) / (pow(other.x, 2) + pow(other.y, 2));

	return result;
}
ComplexNumber ComplexNumber::operator +(const ComplexNumber& other)
{
	ComplexNumber result;

	result.x = this->x + other.x;
	result.y = this->y + other.y;

	return result;
}
ComplexNumber ComplexNumber::operator -(const ComplexNumber& other)
{
	ComplexNumber result;

	result.x = this->x - other.x;
	result.y = this->y - other.y;

	return result;
}