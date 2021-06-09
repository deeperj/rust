#include "Base.h"


int main()
{
    int val;
    cout << "Enter a value: ";
    cin >> val;
    cout << "Enter (O=octal,H=hex,B=binary) base to convert: ";
    char c;
    cin >> c;
    switch(c){
        case('o'):
        case('O'):
            Octal o;
            cout << "octal value for " << val << " is " << o.convert(val) << endl;
            break;
        case('h'):
        case('H'):
            Hex h;
            cout << "Hex value for " << val << " is " << h.convert(val) << endl;
            break;
        case('b'):
        case('B'):
        default:
            Base b;
            cout << "binary value for " << val << " is " << b.convert(val) << endl;
            break;
    }
    return 0;
}