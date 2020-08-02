#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <string>
#include <cmath>


using namespace std;

class complex {
private:
	double re, im;
public:
	complex();
	complex(double a, double b);
	double getReal() {
		return re;
	}
	double getImg() {
		return im;
	}
	complex operator+ (complex);
	complex operator- (complex);
	complex operator* (complex);
	complex operator/ (complex);
	complex operator/ (double);
	complex conj();
	double mod();
};
double complex::mod() {
	return sqrt(pow(re,2) + pow(im,2));
}
complex::complex() {  //default constructor
	re = 0;
	im = 0;
}
complex::complex(double a, double b) {
	re = a;
	im = b;
}
complex complex::conj() {
	return complex(re, -im);
}
complex complex::operator+(complex val2) {
	return complex(getReal() + val2.getReal(), getImg() + val2.getImg());
}
complex complex::operator-(complex val2) {
	return complex(getReal() - val2.getReal(), getImg() - val2.getImg());
}
complex complex::operator*(complex val2) {
	return complex(getReal() * val2.getReal() - getImg() * val2.getImg(),
		getImg() * val2.getReal() - getReal() * val2.getImg());
}
complex complex::operator/(complex val2) {
	return  *this * val2.conj() / (val2 * val2.conj()).getReal();
}
complex complex::operator/(double num) {
	return complex(re / num, im / num);
}

#endif