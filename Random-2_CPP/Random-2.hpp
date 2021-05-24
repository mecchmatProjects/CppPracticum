#pragma once
#include <stdbool.h>

class AlgorithmParametersCpp {
protected:
	int a;
	int c;
	int m;
	int s0;

public:
	AlgorithmParametersCpp();
	AlgorithmParametersCpp(int, int, int, int);

	void inputParameters();
	void outputParameters();

	void readParameters(char* fname);
	void writeParameters(char* fname);

	int getA();
	int getC();
	int getM();
	int getS0();
	void setS0(int);

	bool checkParametersConds();

	void task3_hash_params();
};


class GeneratorCpp {
private:
	AlgorithmParametersCpp* params;

public:
	GeneratorCpp();
	GeneratorCpp(AlgorithmParametersCpp);

	~GeneratorCpp();

	AlgorithmParametersCpp getParams();

	int task2_int_rnd();
	double task2_double_rnd();
};
