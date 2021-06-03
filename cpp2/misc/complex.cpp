




#include "complex.hpp"

double Complex::Real(){
    return real;
}

double Complex::Imag(){
    return imag;
}
Complex::Complex(double a, double b){
    real=a;
    imag=b;
}

Complex Complex::Add(Complex x){
    double a = real;
    double b = imag;
    double c = x.real;
    double d = x.imag;
    double nr=a+c;
    double ni=b+d;
    Complex r(nr,ni);
    return r;
}
Complex Complex::Div(Complex x){
    double a = real;
    double b = imag;
    double c = x.real;
    double d = x.imag;
    double nr=(a*c+b*d)/(c*c+d*d);
    double ni=(b*c-a*d)/(c*c+d*d);
    Complex r(nr,ni);
    return r;
}
Complex Complex::Sub(Complex x){
    double a = real;
    double b = imag;
    double c = x.real;
    double d = x.imag;
    double nr=0;
    double ni=0;
    Complex r(nr,ni);
    return r;
}
Complex Complex::Mul(Complex x){
    double a = real;
    double b = imag;
    double c = x.real;
    double d = x.imag;
    double nr=0;
    double ni=0;
    Complex r(nr,ni);
    return r;
}

int main(){
    Complex a(5,2);
    Complex b(2,2);
    Complex c=a.Mul(b);
    cout << "The result is " << c.Real() << " + j" << c.Imag();
}