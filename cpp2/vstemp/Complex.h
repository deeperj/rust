#pragma once
#include <iostream>

class Complex
{
private:
	double real;
	double imag;
public:
	Complex(double r, double i);
	double getReal();
	double getImag();
};

