#include <iostream>
#include <cmath>

int main()
{   
	std::cout << "Enter n: ";
	int n;
	std::cin >> n;
	if (n < 0)
	{
		std::cout << "Uncorrect input. Program exit." << std::endl;
		return 0;
	}

	double sum = sqrt(3 * n);
	for (int i = n - 1; i > 0; i--)
	{
		sum = sqrt(3 * i + sum);
	}
	std::cout << "Result: " << sum << std::endl;
    return 0;
}