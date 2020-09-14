#include "Complex.h"

int main()
{
    double i, r;
    
    cout << " ******Abdulrahamn Complex Numbers Calculator ******: " << endl;;
    cout << " ******Enter the First Real Number ******: " << endl;;
    cout << " Enter the real part of first number: ";
    cin >> r;
    cout << " Enter the imaginary part of first number: ";
    cin >> i;
    Complex a(r, i);

    cout << " ******Enter the Second Real Number ******: " << endl;;
    cout << " Enter the real part of second number: ";
    cin >> r;
    cout << " Enter the imaginary part of second number: ";
    cin >> i;
    Complex b(r, i);

   // Complex c = a.Pow(2.0);
    //Complex d = a.Root(2.0);
    //std::complex<double> b(r, i);
    //cout << " Value = " << a << endl;
    //cout << " my power = " << c << endl;
    //cout << " my root = " << d << endl;

    Complex c;
    c.Addition(a, b);
    cout << " The addition of two numbers is = " << c << endl;


    Complex d;
    d.Subtraction(a, b);
    cout << " The addition of two numbers is = " << d << endl;

    Complex e;
    e.Multiplication(a, b);
    cout << " The multiplication of two numbers is = " << e << endl;

    Complex f;
    f.Division(a, b);
    cout << " The division of two numbers is = " << f << endl;

}