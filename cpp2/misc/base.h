#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


enum CONVERTER { DEC2OCT, DEC2HEX, DEC2BIN };

class Base{
    private:
    public:
        string convert(int cval);
        string lookup(string d);
};

class Octal: public Base {
   public:
        string convert(int cval);
};


class Hex: public Base {
   public:
        string convert(int cval);
};



#endif