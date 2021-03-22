#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H
#include <iostream>
#include <cmath>
using namespace std;


class Complex{
public:
  double real;
  double imag;

  Complex(){
    this->real = 0.0;
    this->imag = 0.0;
  }

  Complex(float real, float imag){
    this->real = real;
    this->imag = imag;
  }


  Complex operator+(const Complex &obj){
    Complex temp;
    temp.imag = this->imag + obj.imag;
    temp.real = this->real + obj.real;
    return temp;
  }


  Complex operator-(const Complex &obj){
    Complex temp;
    temp.imag = this->imag - obj.imag;
    temp.real = this->real - obj.real;
    return temp;
  }

  Complex operator*(const Complex &obj)
  {
     Complex temp;
     temp.real = this->real * obj.real - this->imag * obj.imag;
     temp.imag = this->imag * obj.real + obj.imag * this->real;
     return temp;

  }

  Complex operator/(const Complex &obj)
  {
    Complex temp;
    temp.real = (this->real * obj.real + this->imag * obj.imag) / (obj.real * obj.real + obj.imag * obj.imag);
    temp.imag = (this->imag * obj.real + this->real * obj.imag) / (obj.real * obj.real + obj.imag * obj.imag);
    return temp;

  }

  void display(){
    char ch;
    if(imag>=0)
      ch ='+';
      else
      ch = '-';
    cout << this->real << ch << abs(this->imag) << "i" << endl;
  }
};

#endif
