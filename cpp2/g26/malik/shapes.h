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

class Rectangle{};

class Circle:public Shape{
private:
double radius;
public:
Circle(double radius);
double area();
};

class Traingle{};

class Square:public Shape{
private:
double side;
public:
double area();
Square(double side);
};
