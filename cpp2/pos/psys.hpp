#pragma once

#include <curses.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using std::cout;
using std::endl;
using std::string;

enum TxnStatus{
  InvalidPin,
  InvalidBal,
  BelowLimit,
  Success,
  Created,
  Inactive,
};

class Account{
  private:
    string pin;
  public:
    string getPin();
    Account(){}
    Account(string);
    void setPin(string);
};

class Transaction{
  private:
  public:
    Account toDebit;
    Account toCredit;
    double amount;
    TxnStatus status;
    Transaction(){}
};

class Bank{
  protected:
    Transaction tx;
  public:
    Bank(){}
    TxnStatus validatePin();
    TxnStatus createTransaction(string pin, double amount);
    Account accounts[1]={{}};
};



