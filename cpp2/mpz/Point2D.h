#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

class Point2D {
private:
    int mx, my;
public:
    Point2D();
    Point2D(int, int);
    int getX();
    int getY();
};

#endif
