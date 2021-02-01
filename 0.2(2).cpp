// Вычисление гипотенузы по имеющимся катетам
#include <stdio.h>
#include <math.h>


int main() {

	double a, b;

	printf("Input values of a and b: ");
	scanf("%lf %lf", &a, &b);

	double c = sqrt(a * a + b * b);
	printf("%lf", c);
}

