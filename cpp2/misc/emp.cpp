#include <iostream>
#include <cmath>
using namespace std;

using std::cout;
using std::endl;
using std::cin;
using std::string;


class Employee {
  public:
    string name;
    string department;
    int age;
    Employee( string name, string dept, int age){
        this->name=name;
        this->department=dept;
        this->age=age;
    }
    void info(){
        cout << name << " works in " << department << " is " << age << " years of age" << endl;
    }
} ;

int main() {
  Employee joe("Joe Bloggs", "Sales", 26);
  Employee s("Sarah Flinstone", "HR", 50);
  joe.info();
  s.info();
  return 0; 
}


