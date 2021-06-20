#include "psys.hpp"

void Bank::validatePin(){

}

TxnStatus Bank::createTransaction(string pin, double amount){
  if(pin.length()!=4){
    return InvalidPin
  }
  return Success;
}