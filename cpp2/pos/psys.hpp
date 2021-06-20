#pragma once

#include <curses.h>
#include <iostream>
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
  public:
    Account(){}
};

class Transaction{
  private:
  public:
    TxnStatus status;
    Transaction(){}
    TxnType createTransaction(string pin, double amount);
};

class Bank{
  private:
  public:
    Bank(){}
    void validatePin();
    Account accounts[1]={{}};
};



