/* Implementation for the Error Class (Error.cpp) */

#include <iostream>
#include "Error.h"
using namespace std;
int Error::getError() const {
   return code;
}
void Error::setError(int c){
	code = c;
}
string Error::getMessage() const{
	return message;
}
void Error::setMessage(string m){
	message = m;
}


