#include "iostream"
#include "string"

using std::cin;
using std::cout;
using std::endl;


#ifndef atm_h
#define atm_h
class account
{
private:
    double balance;

public:
    void menu();
    void displayInfo();
};
class bank {
private:
    int transaction;
public:
    void authorisepin();
    void authoriseamount();

};
class customer {
private:
    double enterpin;
public:
    bool login();
    void insertcard();
   
    void selectopt();
    void changepin();
    void withdrawcash();
    void enteramount();
    void checkbalance();
};
class atm {
private:
    int card;
    int receipt;
public:
    int getUserOpt();
    char displaymenu();
    char displaybalance();

};
#endif