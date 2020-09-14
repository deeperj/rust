#include <iostream>
#include <string>
using std::cin;
using std::endl;
using std::cout;
using std::string;

class Maths{
public:
double PI=22.0/7;
double sqr(double value);
};

class Shape{
public:
Maths math;
double area();
};

class Rectangle:public Shape{
  private:
  double length;
  double width;
  public:
  Rectangle(double lenght,double width);
  double area();
};

class Circle:public Shape{
private:
double radius;
public:
Circle(double radius);
double area();
};

class Triangle:public Shape{
private:
double height;
double base;
public:
Triangle(double height,double base);
double area();
};

class Square:public Shape{
private:
double side;
public:
double area();
Square(double side);
};