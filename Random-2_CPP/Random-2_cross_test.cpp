#include "Random-2.hpp"
extern "C" {
#include "../Random-2_C/Random-2.h"
}
#include <stdio.h>


void reportError(char*);


void cross_test_gen_int() {
	GeneratorCpp gen;
	Parameters params;
	params.a = gen.getParams().getA();
	params.c = gen.getParams().getC();
	params.m = gen.getParams().getM();
	params.s0 = gen.getParams().getS0();
	int n = 1000;
	for (int i = 0; i < n; i++) {
		int v1 = gen.task2_int_rnd();
		int v2 = task2_int_rnd(&params);
		if (v1 != v2) {
			reportError("C and CPP generators produced different values");
			return;
		}
	}
}

void cross_test_gen_double() {
	GeneratorCpp gen;
	Parameters params;
	params.a = gen.getParams().getA();
	params.c = gen.getParams().getC();
	params.m = gen.getParams().getM();
	params.s0 = gen.getParams().getS0();
	int n = 1000;
	for (int i = 0; i < n; i++) {
		double v1 = gen.task2_double_rnd();
		double v2 = task2_double_rnd(&params);
		if (v1 != v2) {
			reportError("C and CPP generators produced different values");
			return;
		}
	}
}


void cross_test_gen() {
	printf("    cross_test_gen_int()...\n");
	cross_test_gen_int();

	printf("    cross_test_gen_double()...\n");
	cross_test_gen_double();
}
