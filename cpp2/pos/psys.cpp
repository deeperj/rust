#include "psys.hpp"

TxnStatus Bank::validatePin(){
  if(tx.toDebit.getPin().length()!=4){
    return InvalidPin;
  }else return Created;
}

TxnStatus Bank::createTransaction(string pin, double amount){
  tx.toDebit=Account(pin);
  tx.amount = amount;
  return validatePin();
}


Account::Account(string pin){
  this->pin=pin;
}

string Account::getPin(){
  return pin;
}

void Account::setPin(string p){
  pin = p;
}
