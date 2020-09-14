#include "Complex.h"

int main()
{

double realA;
double imaginaryA;
double realB;
double imaginaryB;

cout << "enter real(A), imag(A), real(B) and imag(B) >> ";
cin >> realA >> imaginaryA >> realB >> imaginaryB;
cout << endl;

double i, r;
cout << " Enter the real part: ";
cin >> r;
cout << " Enter the imaginary part: ";
cin >> i;

ComplexNumber g = ComplexNumber(realA, imaginaryA);
ComplexNumber h = ComplexNumber(realB, imaginaryB);

Complex a(r, i);

Complex c = a.Pow(2.0);
Complex d = a.Root(2.0);
std::complex<double> b(r, i);
cout << " Value = " << a << endl;
cout << " my power = " << c << endl;
cout << " my root = " << d << endl;
cout << " std power = " << std::pow(b, 2.0) << endl;
cout << " std root = " << std::sqrt(b) << endl;
g.add(g, h);
g.sub(g, h);
g.multiply(g, h);
g.divide(g, h);
return 0;
}