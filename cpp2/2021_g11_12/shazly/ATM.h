#ifndef ATM_H
#define ATM_H
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

class user
{
  private:
    string name;
    string pin;
    int balance;
  public:
    void setname(string Name);
    string getname();
    void setpin(string Pin);
    string getpin();
    void setbalance(int Balance);
    int getbalance();
    bool verifypin(string Pin);
    void userban();
    void withdraw();
    bool isNumber(const string& str);
    void changePin();
    void DisplayBalance();
    void menu();
    void startSession();

};

#endif

