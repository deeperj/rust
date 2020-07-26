#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Math{
public:
  double PI=22.0/7;
  double sqr(double value);
};


class Shape{
public:
  Math maths;
  double area();
  void menu();
};

class Circle:public Shape{
  private:
   double radius;
  public:
   Circle(double r);
  double area();
};

class Triangle:public Shape{
  private:
    double height;
    double base;
  public:
    Triangle(double b,double h);
    double area();
};
class Square:public shape{
  private:
    double side;
  public:
   Square(double s)
   double area()
};
class Rectangle:public Shape{
  private:
    double length;
    double width;
  public:
   Rectangle(double l,double w)
   double area()
};
class
   










     
   )
}

};
class Rectangle;


