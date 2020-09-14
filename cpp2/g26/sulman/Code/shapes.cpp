#include "shapes.h"
using namespace std;

double Shape::area(){
cout << "Select a shape " << endl;
cout << "1. Circle " << endl;
cout << "2. Triangle " << endl;
cout << "3. Rectangle " << endl;
cout << "4. Square " << endl;
cout << "Selected shape:";

int choice;
cin >> choice;
enum shape {circle=1,triangle=2,rectangle=3,square=4};
switch(choice){
case circle:{
cout << "what is the radius? ";
double r;
cin >> r;
Circle c(r);
cout << "the area is " << c.area();
break;
}
case square:{
cout << "what is the side length? ";
double s;
cin >> s;
Square c(s);
cout << "the area is " << c.area();
break;
}
case rectangle:{
  double l,w;
  cout <<"What is Length?"<< endl;
  cin >> l;
  cout<<"What is Width?"<<endl;
  cin >> w;
  Rectangle c(l,w);
  cout<<"The area is:"<< l*w;
  break;
}
case triangle:{
  double h,b;
  cout<<"What is height?"<<endl;
  cin>>h;
  cout<<"What is base?"<<endl;
  cin>>b;
  cout<<"The area is:"<< (h*b)/2<<endl ;
  break;
}
default:
cout << "invalid selection";
exit(0);
break;
}
return 0;
}

Circle::Circle(double r){
radius=r;
}

Square::Square(double s){
side=s;
}
Rectangle::Rectangle(double l,double w){
length=l;
width=w;
}

double Circle::area(){
return math.PI*math.sqr(radius);
}
double Square::area(){
return math.sqr(side);
}

double Maths::sqr(double v){
return v*v;
}
double Rectangle::area(){
  double i,w;
  return i*w;
}

double Triangle::area(){
  double i,l;
  return (i*l)/2;
}



