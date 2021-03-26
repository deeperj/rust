#include "complexnum.h"

int main()
{
  Complex a, b, c;

  cout << "Enter the Real and Imaginary coefficient of the first complex number: " << endl;
  cin >> a.real;
  cin >> a.imag;

  cout << "Enter the Real and Imaginary coefficient of the second complex number: " << endl;
  cin >> b.real;
  cin >> b.imag;

  cout << "Addition Result: ";
  c = a+b;
  c.display();

  cout << "Subtraction Result: ";
  c = a-b;
  c.display();

  cout << "Multiplication Result: ";
  c = a*b;
  c.display();

  cout << "Division Result: ";
  c = a/b;
  c.display();


  return 0;
}
