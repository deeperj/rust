

#include "Complex.h"

int main()
{
  double i, r;
  cout << " Enter the real part: ";
  cin >> r;
  cout << " Enter the imaginary part: ";
  cin >> i;
  Complex a(r,i);
  Complex c=a.Pow(2.0);
  Complex d=a.Root(2.0);
  std::complex<double> b(r,i);
  cout << " Value = " << a << endl;
  cout << " my power = " << c << endl;
  cout << " my root = " << d << endl;
  cout << " std power = " << std::pow(b,2.0) << endl;
  cout << " std root = " << std::sqrt(b) << endl;
}
