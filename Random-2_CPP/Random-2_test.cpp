#include "Random-2.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int errors_counter;

AlgorithmParametersCpp _params(int a, int c, int m, int s0) {
	return AlgorithmParametersCpp(a, c, m, s0);
}

void reportError(char* msg) {
	printf("Помилка тесту: %s\n", msg);
	errors_counter++;
}

void test_checkParametersConds() {
	// m - найб?льше з вказаних натуральних значень
	if (_params(1, 1, 1, 1).checkParametersConds() || _params(2, 1, 1, 1).checkParametersConds()
		|| _params(1, 2, 1, 1).checkParametersConds() || _params(1, 1, 1, 2).checkParametersConds()) {
		reportError("checkParametersConds(): дозволяє m, що не є максимальним значенням");
	}
	if (_params(1, 1, -1, 1).checkParametersConds()) {
		reportError("checkParametersConds(): дозволяє в?д'ємне m");
	}

	// a) m = 2^k, де k - натуральне число:
	if (_params(1, 1, 56, 1).checkParametersConds()) {
		reportError("checkParametersConds(): дозволяє m, що не є степ?нню дв?йки");
	}

	// b) c та m - взаємно прост? числа
	//    (використовуємо те, що m = 2^k)
	if (_params(1, 2, 256, 1).checkParametersConds()) {
		reportError("checkParametersConds(): дозволяє с не взаємо просте з m");
	}

	// c) (a-1) д?литься на вс? прост? числа, що є д?льниками m
	//    (використовуємо те, що m = 2^k)
	if (_params(4, 1, 256, 1).checkParametersConds()) {
		reportError("checkParametersConds(): дозволяє а, що не п?дходить для: (a-1) д?литься на вс? прост? числа, що є д?льниками m");
	}

	// d) c*(a-1) д?литься на 4:
	if (_params(4, 7, 256, 1).checkParametersConds()) {
		reportError("checkParametersConds(): дозволяє (а,c), що не п?дходить для: c*(a-1) д?литься на 4");
	}
}


void test_task1_genParameters(int n) {
	for (int i = 0; i < n; i++) {
		AlgorithmParametersCpp params;
		if (!params.checkParametersConds()) {
			reportError("task1_genParameters(): wrong parameters generated");
			return;
		}
	}
}


void test_task3_hash_params() {
	AlgorithmParametersCpp p0;
	AlgorithmParametersCpp p1(p0);
	p1.task3_hash_params();
	AlgorithmParametersCpp p2(p1);
	p2.task3_hash_params();
	if (p1.getS0() == p0.getS0() && p2.getS0() == p1.getS0()) {
		reportError("task3_hash_params(): перехешування s0 не спрацювало на подв?йному виклику");
	}
}


void test_task2_int_rnd() {
	GeneratorCpp gen;
	int num = 1000;
	int pval = -1;
	for (int i = 0; i < num; i++) {
		int val = gen.task2_int_rnd();
		if (val == pval) {
			reportError("task2_int_rnd(): генератор видав попереднє значення");
			return;
		}
		if (val < 0 || val >= gen.getParams().getM()) {
			reportError("task2_int_rnd(): генератор видав значення за межами д?апазону");
			return;
		}
		pval = val;
	}
}

void test_task2_double_rnd() {
	GeneratorCpp gen;
	int num = 1000;
	double pval = -1;
	for (int i = 0; i < num; i++) {
		double val = gen.task2_double_rnd();
		if (val == pval) {
			reportError("task2_double_rnd(): генератор видав попереднє значення");
			return;
		}
		if (val < 0.0 || val >= 1.0) {
			reportError("task2_double_rnd(): генератор видав значення за межами д?апазону");
			return;
		}
		pval = val;
	}
}

void cross_test_gen();


int main(char** args) {
	errors_counter = 0;
	srand(time(NULL));

	printf("test_checkParametersConds()...\n");
	test_checkParametersConds();

	printf("test_task1_genParameters()...\n");
	test_task1_genParameters(100);

	printf("test_task2_int_rnd()...\n");
	test_task2_int_rnd();

	printf("test_task2_double_rnd()...\n");
	test_task2_double_rnd();

	printf("test_task3_hash_params()...\n");
	test_task3_hash_params();

	printf("cross_test_gen()...\n");
	cross_test_gen();

	if (errors_counter > 0) {
		printf("Знайден? помилки в робот? С модуля: %d", errors_counter);
	}
	else {
		printf("Tests ok");
	}
	scanf_s("%d", &errors_counter);
	return 0;
}
