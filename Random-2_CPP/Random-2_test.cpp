#include "Random-2.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int errors_counter;

AlgorithmParametersCpp _params(int a, int c, int m, int s0) {
	return AlgorithmParametersCpp(a, c, m, s0);
}

void reportError(char* msg) {
	printf("Pomulka testy: %s\n", msg);
	errors_counter++;
}

void test_checkParametersConds() {
	// m - Naybilshe z vkazanuh naturalnuh znachen
	if (_params(1, 1, 1, 1).checkParametersConds() || _params(2, 1, 1, 1).checkParametersConds()
		|| _params(1, 2, 1, 1).checkParametersConds() || _params(1, 1, 1, 2).checkParametersConds()) {
		reportError("checkParametersConds(): dozvolaye m, shcho ne e maksumalnum znachennam");
	}
	if (_params(1, 1, -1, 1).checkParametersConds()) {
		reportError("checkParametersConds(): dozvolae videmne m");
	}

	// a) m = 2^k,  de k -- naturalne chuslo:
	if (_params(1, 1, 56, 1).checkParametersConds()) {
		reportError("checkParametersConds(): dozvolae m, shcho ne e stepenem 2");
	}

	// b) c ta  m - vzaemno prostià
	//    (vukorustovue te, shcho m = 2^k)
	if (_params(1, 2, 256, 1).checkParametersConds()) {
		reportError("checkParametersConds(): dozvolae c ne vzaemno proste z m");
	}

	// c) (a-1) dilutca na vsi prosti chusla, shcho e dilnukamu m
	//    (vukorustovuemo te, shco m = 2^k)
	if (_params(4, 1, 256, 1).checkParametersConds()) {
		reportError("checkParametersConds(): dozvolae a, shcho ne pidhodut dla ymovu");
	}

	// d) c*(a-1) dilutca na 4:
	if (_params(4, 7, 256, 1).checkParametersConds()) {
		reportError("checkParametersConds(): dozvolae(à,c), shco ne pidhodut dla ymovu");
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
		reportError("task3_hash_params(): pereheshuvanna s0 ne spratcuvalo na podviynomu vukluky");
	}
}


void test_task2_int_rnd() {
	GeneratorCpp gen;
	int num = 1000;
	int pval = -1;
	for (int i = 0; i < num; i++) {
		int val = gen.task2_int_rnd();
		if (val == pval) {
			reportError("task2_int_rnd(): generator vudav poperedne znachenna");
			return;
		}
		if (val < 0 || val >= gen.getParams().getM()) {
			reportError("task2_int_rnd(): generator vudav znachenna za mejamu diapazonu");
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
			reportError("task2_double_rnd(): generator vudav poperedne znachenna");
			return;
		}
		if (val < 0.0 || val >= 1.0) {
			reportError("task2_double_rnd(): generator vudav znachenna za mejamu diapazonu");
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
		printf("Znaydeni pomulku v roboti C modula: %d", errors_counter);
	}
	else {
		printf("Tests ok");
	}
	scanf_s("%d", &errors_counter);
	return 0;
}
