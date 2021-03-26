#include <iostream>
#include"complex.hpp"
using std::cout;
using std::endl;
int main() {
Complex A(2,3);
Complex B(2,7);
Complex C =A.add(B);
cout << C.Real()<<"+"<< "j" << C.Imag()<<endl;
Complex D =A.sub(B);
cout << D.Real()<<"-"<<"j"<< D.Imag()<<endl;
Complex E=A.multiply(B);
cout<<E.Real()<<"+"<<"j"<<E.Imag()<<endl;
Complex F=A.division(B);
cout<<F.Real()<<"+"<<"j"<<F.Imag();
}