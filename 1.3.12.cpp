#include <iostream>

int main()
{   
	int num;
	std::cout << "Enter number: ";
	std::cin >> num;
	if (num < 0)
	{
		std::cout << "Uncorrect number input. Program exit." << std::endl;
	}

	std::cout << "Result: ";
	int temp = 1;
	if (num == 0) std::cout << 0;
	else {

		while (temp <= num) temp = temp << 1;

		while (temp > 1) {
			temp = temp >> 1;
			std::cout << (((temp & num) != 0) ? 1 : 0);
		}
	}

    return 0;
}