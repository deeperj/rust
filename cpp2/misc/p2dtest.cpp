

#include "point2d.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(){
    Point2D a(2,4);
    Point2D b(10,12);
    Point2D midpoint = a.midPoint(b);
    double grad = a.gradient(b);
    cout << "the gradient is " << grad; 
    return 0;
}