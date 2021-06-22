#include <iostream> 
#include <cmath> 
int main() {
	int n; float a;
	std::cout << "Введіть n: ";
	std::cin >> n;
	a = sqrt(2);
	for (int i = 1; i < n; i++) {
		a = sqrt(2 + a);
	}
	std::cout << a;
	return 0;
}
