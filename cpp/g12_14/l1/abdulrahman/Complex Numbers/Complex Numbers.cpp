#include "Complex.h"

Complex::Complex()
{
	mReal = 0.0;
	mImag = 0.0;
}
//------------------------------------------------------------------------------
Complex::Complex(const Complex& aComplex)
{
	mReal = aComplex.Real();
	mImag = aComplex.Imag();
}
//------------------------------------------------------------------------------
Complex::Complex(double aReal, double aImag)
{
	mReal = aReal;
	mImag = aImag;
}
//------------------------------------------------------------------------------
double Complex::Real(void) const
{
	return mReal;
}
//------------------------------------------------------------------------------
double Complex::Imag(void) const
{
	return mImag;
}
//------------------------------------------------------------------------------
double Complex::Magnitude(void)
{
	return sqrt(mReal * mReal + mImag * mImag);
}
//------------------------------------------------------------------------------
double Complex::Argument(void)
{
	double cTemp = 22.0 / 7;
	if (mImag == 0)
		cTemp = 90;
	else
		cTemp = atan(mImag / mReal) * 180 / cTemp;
	return cTemp;
}
//------------------------------------------------------------------------------
void Complex::SetPolar(double aMagnitude, double aArgument)
{
	double cTemp = 22.0 / 7;
	aArgument = aArgument * cTemp / 180;
	mReal = aMagnitude * cos(aArgument);
	mImag = aMagnitude * sin(aArgument);
}
//------------------------------------------------------------------------------
// friend function - NOT a member
// overloaded insertion operator
ostream& operator<<(ostream& aStream, Complex& aComplex)
{
	aStream << aComplex.mReal;
	aComplex.mImag < 0.0 ?
		aStream << " - " << -aComplex.mImag << CMPLXCHAR :
		aStream << " + " << aComplex.mImag << CMPLXCHAR;
	return aStream;
}

Complex Complex::Pow(int n) {
	Complex a(mReal, mImag);
	double mag = a.Magnitude();
	double arg = a.Argument();
	mag = pow(mag, n);
	arg = arg * n;
	a.SetPolar(mag, arg);
	return a;
}

Complex Complex::Root(int n) {
	Complex a(mReal, mImag);
	double mag = a.Magnitude();
	double arg = a.Argument();
	mag = pow(mag, 1.0 / n);
	arg = arg / n;
	a.SetPolar(mag, arg);
	return a;
}

void Complex::Addition(Complex a, Complex b) {

	mReal = a.mReal + b.mReal;
	mImag = a.mImag + b.mImag;
}

void Complex::Subtraction(Complex a, Complex b) {

	mReal = a.mReal - b.mReal;
	mImag = a.mImag - b.mImag;
}

void Complex::Multiplication(Complex a, Complex b) {

	//Multiply Number1 Real Part with Number 2 Real Part and store in a variable
	double n1Rn2R = a.mReal * b.mReal;

	//Multiply Number 1 Imaginary Part with Number 2 Imaginary Part
	double n1In2I = a.mImag * b.mImag;

	//calculate the real part of resulting number
	mReal = n1Rn2R - n1In2I;

	//Multiply Number 1 Imaginary Part with Number 2 Real Part

	double n1In2R = a.mImag * b.mReal;

	//Multiply Number 2 Imaginary Part with Number 1 Real Part

	double n2In1R = b.mImag * a.mReal;

	mImag = n1In2R + n2In1R;
}

void Complex::Division(Complex a, Complex b) {

	mReal = ((a.mReal * b.mReal) + (a.mImag * b.mImag))/(pow(b.mReal,2)+ pow(b.mImag, 2));
	mImag = ((a.mImag * b.mReal) - (b.mImag * a.mReal))/(pow(b.mReal, 2) + pow(b.mImag, 2));
}

