#include <iostream>

int main()
{   
	double h = 0.1;
	double min = 0;
	double max = 1;
	std::cout << "y = sin(x), x -> [0, 1], step -> 0.1:" << std::endl;
	for (double x = min; x <= max; x += h)
	{
		std::cout << "y(" << x << ") = " << sin(x) << std::endl;
	}
    return 0;
}