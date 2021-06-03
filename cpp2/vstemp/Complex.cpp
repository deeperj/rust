#include "Complex.h"

Complex::Complex(double r, double i) {//r=5, i=6
	real = r; //real=5
	imag = i; //imag=6
}

double Complex::getReal() {
	return real;
}

double Complex::getImag() {
	return imag;
}
