#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <complex>

using std::cin;
using std::cout;
using std::ostream;
using std::endl;
using std::string;
using std::vector;

#define CMPLXCHAR 'j'

class Complex {
private:
double mReal;
double mImag;
protected:
public:
Complex();
Complex(const Complex&); // copy constructor
Complex(double, double);
double Real(void) const;
double Imag(void) const;
double Magnitude(void);
double Argument(void); // in degree
void SetPolar(double, double); // second argument in degree

Complex Pow(int n);
Complex Root(int n);

// friend function - can access members but NOT a member
// BE CAREFUL when choosing a friend!
// overload insertion operator
friend ostream& operator<<(ostream&, Complex&);
};
class ComplexNumber {

public:

double real;
double imaginary;

void add(ComplexNumber g, ComplexNumber h);
void sub(ComplexNumber g, ComplexNumber h);
void multiply(ComplexNumber g, ComplexNumber h);
void divide(ComplexNumber g, ComplexNumber h);

/*
* Constructor to create complex numbers
*/
ComplexNumber(double real, double imaginary) {
this->real = real;
this->imaginary = imaginary;
}
};

#endif