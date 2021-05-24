#include "Random-2.hpp"
#include <stdlib.h>
#include <stdio.h>


AlgorithmParametersCpp::AlgorithmParametersCpp() {
	int st = 5 + (rand() % 11);
	int m = 1 << st;
	int a = rand() % (m - 4) + 4;
	a = (a / 4) * 4 + 1;

	this->m = m;
	this->a = a;
	this->c = (3 + (2 * rand())) % m;
	this->s0 = (5 + rand()) % m;
}

AlgorithmParametersCpp::AlgorithmParametersCpp(int a, int c, int m, int s0) {
	this->a = a;
	this->c = c;
	this->m = m;
	this->s0 = s0;
}

void AlgorithmParametersCpp::inputParameters() {
	scanf_s("%d", &this->a);
	scanf_s("%d", &this->c);
	scanf_s("%d", &this->m);
	scanf_s("%d", &this->s0);
}

void AlgorithmParametersCpp::outputParameters() {
	printf("Parameters = {\n");
	printf("    a  = %d\n", this->a);
	printf("    c  = %d\n", this->c);
	printf("    m  = %d\n", this->m);
	printf("    s0 = %d\n", this->s0);
	printf("}\n");
}

void AlgorithmParametersCpp::readParameters(char* fname) {
}

void AlgorithmParametersCpp::writeParameters(char* fname) {
}


int AlgorithmParametersCpp::getA() {
	return this->a;
}
int AlgorithmParametersCpp::getC() {
	return this->c;
}
int AlgorithmParametersCpp::getM() {
	return this->m;
}
int AlgorithmParametersCpp::getS0() {
	return this->s0;
}
void AlgorithmParametersCpp::setS0(int s0) {
	this->s0 = s0;
}


bool AlgorithmParametersCpp::checkParametersConds() {
	int a = this->a;
	int c = this->c;
	int m = this->m;
	int s0 = this->s0;

	//  m mae bytu naturalnum chuslom, ta dla "a) m = 2^k, de k - natyralne chuslo" (k>0)
	if (a < 1 || c < 1 || m < 2 || s0 < 0) {
		return false;
	}

	// m mae bytu maksumalnum sered parametriv
	if (a >= m || c >= m || s0 >= m) {
		return false;
	}

	// a)  m = 2^k, de k - natyralne chuslo:
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

void AlgorithmParametersCpp::task3_hash_params() {
	this->s0 = (rand() + this->s0) % this->m;
}


GeneratorCpp::GeneratorCpp() {
	this->params = new AlgorithmParametersCpp();
}

GeneratorCpp::GeneratorCpp(AlgorithmParametersCpp params) {
	this->params = new AlgorithmParametersCpp(params);
}

GeneratorCpp::~GeneratorCpp() {
	delete this->params;
}

AlgorithmParametersCpp GeneratorCpp::getParams() {
	return *this->params;
}

int GeneratorCpp::task2_int_rnd() {
	int v = (int)(((long)params->getA() * (long)params->getS0() + (long)params->getC()) % (long)params->getM());
	params->setS0(v);
	return v;
}

double GeneratorCpp::task2_double_rnd() {
	int ival = this->task2_int_rnd();
	return (ival + (double)1) / (params->getM() + (double)1);
}
