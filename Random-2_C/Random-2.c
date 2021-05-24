#include "Random-2.h"
#include <stdio.h>
#include <stdlib.h>


Parameters inputParameters(Parameters params) {
	Parameters ret;
	scanf_s("%d", &ret.a);
	scanf_s("%d", &ret.c);
	scanf_s("%d", &ret.m);
	scanf_s("%d", &ret.s0);
	return ret;
}

void outputParameters(Parameters params) {
	printf("Parameters = {\n");
	printf("    a  = %d\n", params.a);
	printf("    c  = %d\n", params.c);
	printf("    m  = %d\n", params.m);
	printf("    s0 = %d\n", params.s0);
	printf("}\n");
}

Parameters readParameters(char* fname) {

}

void writeParameters(char* fname, Parameters params) {

}


bool checkParametersConds(Parameters params) {
	int a = params.a;
	int c = params.c;
	int m = params.m;
	int s0 = params.s0;

	// m mae bytu naturalnum chuslom, ta dla "a) m = 2^k, de k - natyralne chuslo" (k>0)
	if (a < 1 || c < 1 || m < 2 || s0 < 0) {
		return false;
	}

	// m mae bytu maksumalnum sered parametriv
	if (a >= m || c >= m || s0 >= m) {
		return false;
	}

	// a) m = 2^k, de k - natyralne chuslo:
	int val = m;
	while (val > 1) {
		if (val % 2 != 0) {
			return false;
		}
		val /= 2;
	}

	// b) c ta m - vzaemnoprosti chusla
	//    (vukorustovye te, shcho m = 2^k)
	if (c % 2 == 0) {
		return false;
	}

	// c) (a-1) dilutca na vsi prosti chusla, shcho e dilnukamu m
	//    (vukorustovyemo te, shcho m = 2^k)
	if (a <= 2 || a % 2 == 0) {
		return false;
	}

	// d) c*(a-1) dilutca na 4:
	if ((c * (a - 1)) % 4 != 0) {
		return false;
	}

	//vsi ymovu yspishno perevireno:
	return true;
}


Parameters task1_genParameters() {
	int st = 5 + (rand() % 11);
	int m = 1 << st;
	int a = rand() % (m - 4) + 4;
	a = (a / 4) * 4 + 1;

	Parameters ret;
	ret.m = m;
	ret.a = a;
	ret.c = (3 + (2 * rand())) % m;
	ret.s0 = (5 + rand()) % m;
	return ret;
}


int task2_int_rnd(Parameters* params) {
	int v = (int) (((long) params->a * (long) params->s0 + (long) params->c) % (long) params->m);
	params->s0 = v;
	return v;
}

double task2_double_rnd(Parameters* params) {
	int ival = task2_int_rnd(params);
	return (ival + (double)1) / (params->m + (double)1);
}


Parameters* task3_hash_params(Parameters* params) {
	params->s0 = (rand() + params->s0) % params->m;
	return params;
}


Parameters* task4_createParameters(int n, bool rnd) {
	return NULL;
}

double* task4_generateVector(Parameters* params) {
	return NULL;
}

bool task4_checkCorrel(Parameters* params, int num) {
	return false;
}


double task5_calcSize(int n) {
	return .0;
}
