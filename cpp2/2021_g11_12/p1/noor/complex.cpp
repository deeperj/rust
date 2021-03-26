#include "complex.hpp"

Complex Complex::add(Complex no){
return Complex(this->mReal +no.mReal, this->mImag+no.mImag);
}
Complex Complex::sub(Complex no){
return Complex(this->mReal-no.mReal, this->mImag-no.mImag);
}
Complex Complex::multiply(Complex no){
int Real;
int Imaginary;
Real = (mReal * no.mReal) + (mImag* no.mImag)*(-1);
Imaginary = (mReal*no.mImag) + (no.mReal*mImag);
return Complex(Real , Imaginary);
}

Complex Complex::division(Complex no){
Complex upper(0,0);
Complex lower(0,0);
Complex conjugate(no.mReal, -1 * no.mImag);
upper= this->multiply(conjugate);
lower= no.multiply(conjugate);
double Real;
double Imaginary;
Real = upper.mReal/lower.mReal;
Imaginary=upper.mImag/lower.mReal;
return Complex(Real, Imaginary);
}
