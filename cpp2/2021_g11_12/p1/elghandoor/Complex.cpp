#include "Complex.h"
#define CMPLXCHAR 'j'
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

Complex Complex::Add(Complex num) {
	double answerReal = num.Real() + this->mReal;
	double answerImag = num.Imag() + this->mImag;
	Complex answer = Complex(answerReal, answerImag);
	return answer;

}
Complex Complex::Subtract(Complex num) {
	double answerReal = this->mReal - num.Real();
	double answerImag = this->mImag - num.Imag();
	Complex answer = Complex(answerReal, answerImag);
	return answer;

}
Complex Complex::Multiply(Complex num) {
	double answerReal = num.Real() * this->mReal - num.Imag() * this->mImag;
	double answerImag = num.Real() * this->mImag + num.Imag() * this->mReal;
	Complex answer = Complex(answerReal, answerImag);
	return answer;
}

Complex Complex::Multiply(Complex a, Complex b) {
	double answerReal = a.Real() * b.Real() - a.Imag() * b.Imag();
	double answerImag = a.Real() * b.Imag() + b.Real() * a.Imag();
	Complex answer = Complex(answerReal, answerImag);
	return answer;
}

Complex Complex::Division(Complex num) {
	double conjugateR = num.Real();
	double conjugateI = num.Imag() * -1;
	Complex conjugate = Complex(conjugateR, conjugateI);
	Complex Numerator = this->Multiply(conjugate);
	Complex denamenator = Multiply(conjugate, num);
	Complex answer = Complex(Numerator.Real() / denamenator.Real(), Numerator.Imag() / denamenator.Real());

	return answer;
}
