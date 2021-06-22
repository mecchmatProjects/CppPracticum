#include <iostream>

using namespace std;

int main()

{

	int a, b;



	cout << "Enter a, b :"; cin >> a >> b;

	int max;


	((a >= b) && (max = a)) || ((b >= a) && (max = b));

	cout << "max = " << max;

	return 0;

}
