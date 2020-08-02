#include "Complex.h"

int main()
{
    double im1, im2, re1, re2;
    cout << "Enter the real and imaginary values for z1 and z2 equations";
    cout << "\nEnter the real part for z1: ";
    cin >> re1;
    cout << "Enter the imaginary part for z1: ";
    cin >> im1;
    cout << "\nEnter the real part for z2: ";
    cin >> re2;
    cout << "Enter the imaginary part for z2: ";
    cin >> im2;
    complex v1(re1, im1);
    complex v2(re2, im2);
    if ((v1 + v2).getImg() < 0) {
        cout << "The addition values of z1 and z2 equation is " << (v1 + v2).getReal() << " - j" << -(v1 + v2).getImg() << endl;
    }
    else {
        cout << "The addition values of z1 and z2 equation is " << (v1 + v2).getReal() << " + j" << (v1 + v2).getImg() << endl;
    }
    cout << "The magnitude of addition values : " << (v1 + v2).mod() << endl;

    if ((v1 - v2).getImg() < 0) {
        cout << "The subtraction values of z1 and z2 equation is  " << (v1 - v2).getReal() << " - j" << -(v1 - v2).getImg() << endl;
    }
    else {
        cout << "The subtraction values of z1 and z2 equation is  " << (v1 - v2).getReal() << " + j" << (v1 - v2).getImg() << endl;
    }
    cout << "The magnitude of subtraction values : " << (v1 - v2).mod() << endl;

    if ((v1 * v2).getImg() < 0) {
        cout << "The multiplication values of z1 and z2 equation is  " << (v1 * v2).getReal() << " - j" << -(v1 * v2).getImg() << endl;
    }
    else {
        cout << "The multiplication values of z1 and z2 equation is  " << (v1 * v2).getReal() << " + j" << (v1 * v2).getImg() << endl;
    }
    cout << "The magnitude of multiplication values : " << (v1 * v2).mod() << endl;

    if ((v2 * v2.conj()).getReal() != 0 && (v2 * v2.conj()).getReal() > 0) {
        cout << "The division values of z1 and z2 equation is  " << (v1 / v2).getReal() << " + j" << (v1 / v2).getImg() << endl ;
        cout << "The magnitude of division values : " << (v1 / v2).mod() << endl;
    }
    else if((v2 * v2.conj()).getReal() != 0 && (v2 * v2.conj()).getReal() < 0) {
        cout << "The division values of z1 and z2 equation is  " << (v1 / v2).getReal() << " + j" << -(v1 / v2).getImg() << endl;
        cout << "The magnitude of division values : " << (v1 / v2).mod() << endl;
    }
    else {
        cout << "The division values of z1 and z2 equation is undefined" << endl ;
    }
}