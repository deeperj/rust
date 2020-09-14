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
aStream << " - " << CMPLXCHAR << -aComplex.mImag :
aStream << " + " << CMPLXCHAR << aComplex.mImag;
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

//________________________________________________________________________
void ComplexNumber::add(ComplexNumber g, ComplexNumber h) {


double real = g.real + h.real;
double imaginary = g.imaginary + h.imaginary;
ComplexNumber c = ComplexNumber(real, imaginary);
cout << "a + b = " << c.real << " + (" << c.imaginary << ") * i" << endl;
}

void ComplexNumber::sub(ComplexNumber g, ComplexNumber h) {

double real = g.real - h.real;
double imaginary = g.imaginary - h.imaginary;
ComplexNumber c = ComplexNumber(real, imaginary);
cout << "a - b = " << c.real << " + (" << c.imaginary << ") * i" << endl;
}

void ComplexNumber::multiply(ComplexNumber g, ComplexNumber h) {


double real = g.real * h.real - g.imaginary * h.imaginary;
double imaginary = g.imaginary * h.real + g.real * h.imaginary;
ComplexNumber c = ComplexNumber(real, imaginary);
cout << "a * b = " << c.real << " + (" << c.imaginary << ") * i" << endl;
}

void ComplexNumber::divide(ComplexNumber g, ComplexNumber h) {


double real = (g.real * h.real + g.imaginary * h.imaginary) / (g.real * h.real + g.imaginary * h.imaginary);
double imaginary = (g.imaginary * h.real - g.real * h.imaginary) / (g.real * h.real + g.imaginary * h.imaginary);
ComplexNumber c = ComplexNumber(real, imaginary);
cout << "a : b = " << c.real << " + (" << c.imaginary << ") * i" << endl;
}