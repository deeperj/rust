#include "shapes.h"

double Shape::area(){
cout << "Select a shape " << endl;
cout << "1. Circle " << endl;
cout << "2. Triangle " << endl;
cout << "3. Rectangle " << endl;
cout << "4. Square " << endl;

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
case triangle:{
  cout << "What is base?";
  double b;
  cin >> b;
  cout << "What is height?";
  double h;
  cin >> h;

  cout << "the area is " << (h*b)/2<<endl;
  break;
}
case rectangle:{
  cout << "What is Width?";
  double w;
  cin >> w;
  cout << "whats is length?";
  double l;
cin >> l;
cout <<"the area is"<< (l*w)<<endl;
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

double Circle::area(){
return math.PI*math.sqr(radius);
}
double Square::area(){
return math.sqr(side);
}

double Maths::sqr(double v){
return v*v;
}