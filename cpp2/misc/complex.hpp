




#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Complex{
private:
    double real;
    double imag;
public:
    Complex(double a, double b);
    double Real();
    double Imag();
    Complex Add(Complex b);
    Complex Sub(Complex b);
    Complex Div(Complex b);
    Complex Mul(Complex b);
};
