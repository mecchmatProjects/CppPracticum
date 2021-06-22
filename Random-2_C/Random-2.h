#pragma once
#include <stdbool.h>

typedef struct AlgorithmParameters {
	int a;
	int c;
	int m;
	int s0;
} Parameters;

Parameters inputParameters(Parameters params);
void outputParameters(Parameters params);

Parameters readParameters(char* fname);
void writeParameters(char* fname, Parameters params);

bool checkParametersConds(Parameters params);

Parameters task1_genParameters();

int task2_int_rnd(Parameters* params);
double task2_double_rnd(Parameters* params);

Parameters* task3_hash_params(Parameters* params);

Parameters* task4_createParameters(int n, bool rnd);
double*     task4_generateVector(Parameters* params);
bool        task4_checkCorrel(Parameters*, int num);

double     task5_calcSize(int n);
