#include "Point2D.h"
#include <iostream>
using namespace std;

double Point2D::getValuemx() const{
    return mx;
}
double Point2D::getValuemy() const{
    return my;
}

void Point2D::setValuemx(double X){
    X = mx;
}

void Point2D::setValuemy(double Y){
    Y = my;
}

Point2D::Point2D(double X, double Y){
    X = mx;
    Y = my;
}

Point2D::Point2D(Point2D &p){
    mx = p.mx;
    my = p.my;
}

Point2D Point2D::midPoint(Point2D &p2){
    Point2D p1(mx, my);
    p1.mx = (mx+p2.mx)/2;
    p1.my = (my + p2.my)/2;
    
    return p1;
}


