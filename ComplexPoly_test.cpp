#include <iostream>
#include "ComplexPoly.h"
using namespace std;

int main()
{
	ComplexPoly a;

	a.input_by_space();

	cout << endl << a << "\n\n";

	cout << "Enter complex number (z = x + yi) to calculate ComplexPolynom value from:\n";
	double x, y;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	ComplexNumber z(x, y);
	cout << "ComplexPoly(z) = " << a.Value(z) << "\n\n";

	ComplexPoly der = a.Derivative();
	cout << "Derivative:" << endl << der << "\n\n";

	cout << "DerivativePoly(z) = " << der.Value(z) << "\n\n";

	a.writePolynomToFile();
	cout << "\n";

	cout << "Random generated polynom (size = 4):\n";
	a.generate(4);
	cout << a << "\n\n";

	ComplexPoly denom;
	denom.input_by_space();
	cout << endl << denom << "\n\n";
	
	cout << "Polynoms division:\n";
	cout << a / denom << "\n\n";

	cout << "Rest of polynoms division:\n";
	cout << a % denom << "\n\n";
	
	cout << "Polynoms sum:\n";
	cout << a + denom << "\n\n";

	cout << "Polynoms difference:\n";
	cout << a - denom << "\n\n";

	cout << "ComplexPoly(z) + - / * delta test\n";
	cout << "delta = ";
	double delta;
	cin >> delta;
	cout << '\n';

	cout << "ComplexPoly(z) + delta:\n";
	cout << a + delta << "\n\n";

	cout << "ComplexPoly(z) - delta:\n";
	cout << a - delta << "\n\n";

	cout << "ComplexPoly(z) * delta:\n";
	cout << a * delta << "\n\n";

	cout << "ComplexPoly(z) / delta:\n";
	cout << a / delta << "\n\n";

	return 0;
}