#include "Arithmetic.hpp"

Arithmetic::Arithmetic(float a, float b) {
	this->a = a;
	this->b = b;
}

float Arithmetic::Calculate() {
	return a*a + b*b;
}

Arithmetic::Arithmetic(){}
Sub::Sub(){}
Div::Div(){}