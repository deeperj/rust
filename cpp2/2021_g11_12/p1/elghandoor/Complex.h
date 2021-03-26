
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

#define CMPLXCHAR 'j';

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
	Complex Add(Complex num);
	Complex Subtract(Complex num);
	Complex Multiply(Complex num);
	Complex Multiply(Complex a, Complex b);
	Complex Division(Complex num);
	// friend function - can access members but NOT a member
	// BE CAREFUL when choosing a friend!
	// overload insertion operator
	friend ostream& operator<<(ostream&, Complex&);

};