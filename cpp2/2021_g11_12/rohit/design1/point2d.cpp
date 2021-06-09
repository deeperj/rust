#include "point2d.h"

Point2D::Point2D(double Y, double X) {
    mx = X;
    my = Y;
}
 double Point2D :: X(){
  return mx-1;
}
double Point2D :: Y(){
  return my-1;
}