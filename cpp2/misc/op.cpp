#include <iostream>
#include <cmath>
using namespace std;

using std::cout;
using std::endl;
using std::cin;

enum op{ ADD='+', MUL= '*', SUB = '-', DIV = '/'};

struct complex { double real; double imag;};

class complex2 {
  public:
    double real;
    double imag;
} ;

int main() {
  complex2 a,b,d;
  char c;
  cout << "Enter format a.r a.i + b.r b.i <enter>. where a.r,a.i,b.r,b.i are floats and + is either +,-,/,*: ";
  cin >> a.real >> a.imag >> c >> b.real >> b.imag;

  if(c='+'){
    d.real = a.real + b.real;
    d.imag = a.imag + b.imag;
  }
  if(c='-'){
    d.real = a.real - b.real; 
    d.imag = a.imag - b.imag; 
  }
  cout << a.real << "+j" << a.imag << c << b.real << "+j" << b.imag << "=" << d.real << "+j" << d.imag << endl;
  // A variable name must be declare before use
  return 0; 
}


