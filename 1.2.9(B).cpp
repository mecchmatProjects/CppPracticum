#include <iostream>
#include <cmath>

double fact(int N)
{
	if (N < 0)
		return 0;
	if (N == 0)
		return 1;
	else
		return N * fact(N - 1);
}

int main()
{   
	double x;
	int n;

	std::cout << "Enter x < 1: ";
	std::cin >> x;
	if (x >= 1)
	{
		std::cout << "x > 0. Program exit." << std::endl;
		return 0;
	}

	std::cout << "Enter n: ";
	std::cin >> n;
	if (n < 0)
	{
		std::cout << "Uncorrect 'n' input. Program exit" << std::endl;
		return 0;
	}

	double res = 1;
	for (size_t i = 1; i <= n; i++)
	{
		res += (pow(x, i) / fact(i));
	}
	std::cout << "Result: " << res << std::endl;

    return 0;
}