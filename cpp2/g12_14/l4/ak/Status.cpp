/* Implementation for the Status Class (Status.cpp) */
#include <iostream>
#include "Status.h"
using namespace std;
int Status::getStatus() const {
   return code;
}
void Status::setStatus(int c){
	code = c;
}
string Status::getMessage() const{
	return message;
}
void Status::setMessage(string m){
	message = m;
}
