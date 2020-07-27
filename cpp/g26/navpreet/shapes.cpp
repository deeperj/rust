#include "shapes.h"

Triangle::Triangle(double b, double h){
  height=h;
  base=b;
}

double Triangle::area(){
  return 0.5 * base * height;
}

double Shape::area(){
  return 0;
}

void Shape::menu(){
  enum shape {triangle=1, rectangle=3, circle=2, square=4};
  cout << "Select a shape" << endl;
  cout << "1. Triangle" << endl;
  cout << "2. Circle" << endl;
  cout << "3. Rectangle" << endl;
  cout << "4. Square" << endl;
  int choice;
  cin >> choice;
  switch(choice){
    case triangle:{
      double h,b;
      cout << "Enter the height" << endl;
      cin >> h;
      cout << "Enter the base" << endl;
      cin >>b;
      Triangle t(b,h);
      cout << "The area is " << t.area() << endl;
      break;
    }
    case circle:{
      double r;
      cout << "Enter the radius" << endl;
      cin >> r;
      //Circle t(r);
      //cout << "The area is " << t.area() << endl;
      break;
    }
    default:{
      cout << "invalid selection" << endl;
    }
  }
}
