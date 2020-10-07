#include "Point2D.h"
#include <iostream>
using namespace std;

int main() {
    
    Point2D p1(1,8);
    Point2D p2(8,9);
    
    Point2D p=p1.midPoint(p2);
    
    cout <<p.getValuemx()<<","<<p.getValuemy()<< endl;
}