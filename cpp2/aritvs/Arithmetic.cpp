#include "Arithmetic.hpp"

Arithmetic::Arithmetic(float a, float b) {
	this->a = a;
	this->b = b;
}

float Arithmetic::Calculate() {
	return a*a + b*b;
}

Arithmetic::Arithmetic(){}

Sub::Sub(float a, float b):Arithmetic(a,b){}
Div::Div(float a, float b):Arithmetic(a,b){}
Sum::Sum(float a, float b):Arithmetic(a,b){}
Mul::Mul(float a, float b):Arithmetic(a,b){}

float Sub::Calculate(){
	return a - b;
}
float Div::Calculate(){
	return a/b;
}
float Sum::Calculate(){
	return a+b;
}
float Mul::Calculate(){
	return a*b;
}