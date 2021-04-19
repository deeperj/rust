#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

class Car{
public:
string color;
string model;
string name;
double price;
void drive(){
cout << "I am driving";
}
};
int main(){
Car car1; // Car is the class and car1 is the object instance of Car

car1.drive();

}