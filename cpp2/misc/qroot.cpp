#include <iostream>
#include <cmath>
using namespace std;


double qroots(float a, float b, float c, float *x1, float *x2){
    float discriminant, realPart, imaginaryPart;

    discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        *x1 = (-b + sqrt(discriminant)) / (2*a);
        *x2 = (-b - sqrt(discriminant)) / (2*a);
    }
    
    else if (discriminant == 0) {
         * x1 = -b/(2*a);
    }

    else {
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-discriminant)/(2*a);
    }
    return discriminant;
  }

  int test_qroot(){
    float a, b, c, d, x1, x2;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;

    d=qroots(a,b,c, &x1, &x2);

    if (d > 0) {
        cout << "Roots are real and different." << endl;
    }
    else if (d == 0) {
        cout << "Roots are real and same." << endl;
    }
    else {
        cout << "Roots are complex."  << endl;
        return -1;
    }
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    return 0;

  }

#include "add.hpp"

int main() {
  double a,b,d;
  char c;
  cout << "Enter format a + b <enter>. where a, b are floats and + is either +,-,/,*: ";
  cin >> a >> c >> b;

  if(c='+'){
    d = a + b;
  }
  if(c='-'){
    d = a - b; 
  }
  if(c='*'){
    d = a * b;
  }
  if(c='/'){
    d = a / b;
  }
  cout << a << c << b << "=" << d << endl;
  // A variable name must be declare before use
  return 0; 
}


