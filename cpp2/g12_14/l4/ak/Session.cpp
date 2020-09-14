/* Implementation for the Session Class (Session.cpp) */
#include <iostream>
#include "Session.h"
using namespace std;
Status Session::getStatus() const{
	return status;
}
void Session::setStatus(Status S){
	status = S;
}
void Session::setUser(Details D){
	user = D;
}
void Session::createUser(Details u){
	user = u;
}
void Session::ValidatePassword(){
	
}
void Session::ValidateUser(){
	
}
void Session::allErrors(){
	
}
