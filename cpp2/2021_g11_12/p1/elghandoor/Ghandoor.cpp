#include "Complex.h"
#define CMPLXCHAR 'j'
int main()
{
	string choice;
	double i, r, I, R;
	cout << " Enter the real part: " << endl;
	cin >> r;
	cout << " Enter the imaginary part: " << endl;
	cin >> i;
	cout << " enter the real part " << endl;
	cin >> R;
	cout << " Enter the imaginary part: " << endl;
	cin >> I;
	Complex a(r, i);
	Complex k(R, I);
	Complex Powera = a.Pow(2.0);
	Complex Powerk = k.Pow(2.0);
	Complex rootk = k.Root(2.0);
	Complex roota = a.Root(2.0);
	Complex Addition = a.Add(k);
	Complex Subtraction = a.Subtract(k);
	Complex Multiplicaton = a.Multiply(k);
	Complex Divide = a.Division(k);
	std::complex<double> b(r, i);

	cout << " Value = " << a << endl;
	cout << " Value = " << k << endl;
	cout << " my 1 power = " << Powera << endl;
	cout << " my 1 root = " << roota << endl;
	cout << " my 2 power = " << Powerk << endl;
	cout << " my 2 root = " << rootk << endl;
	cout << " std power = " << std::pow(b, 2.0) << endl;
	cout << " std root = " << std::sqrt(b) << endl;
	cout << " Addition is = " << Addition << endl;
	cout << " Subtraction is = " << Subtraction << endl;
	cout << " Multiplication is = " << Multiplicaton << endl;
	cout << " Division is = " << Divide << endl;
}