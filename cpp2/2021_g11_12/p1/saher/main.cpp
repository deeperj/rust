#include "complex.hpp"


int main()
{
  double i, r, imreal,imim ;
  cout << " Enter the real part: ";
  cin >> r;
  cout << " Enter the imaginary part: ";
  cin >> i;
  cout << " Enter the real part: ";
  cin >> imreal;
  cout << " Enter the imaginary part: ";
  cin >> imim;
  Complex p(imreal , imim);
  Complex a(r,i);
  Complex c=a.Pow(2.0);
  Complex d=a.Root(2.0);
  Complex z=p.Pow(2.0);
  Complex u=p.Root(2.0);
  Complex l=a.Multiplication(p);
  Complex v=a.Addition(p);
  Complex e=a.Subtraction(p);
  Complex y=a.Division(p);
    
  std::complex<double> b(r,i);
  cout << " Value = " << a << endl;
  cout << " my power = " << c << endl;
  cout << " my root = " << d << endl;
  cout << " std power = " << std::pow(b,2.0) << endl;
  cout << " std root = " << std::sqrt(b) << endl;
    cout << " the Addition = " << v << endl;
    cout << " the Multiplication =" <<  l << endl;
    cout << " The Division is = " << y << endl;
    cout << "the Subtraction is = " << e << endl;
  
  
}
