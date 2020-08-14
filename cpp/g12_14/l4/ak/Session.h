/* Header for the Session class (Session.h) */
#ifndef SESSION_H
#define SESSION_H
#include <string>   // using string
#include "Status.cpp"
#include "Error.cpp"
#include "Details.h"
using namespace std;
const int MAX=20;
class Session{
	private:
		Details user;
		Status status;
		Details vaildUsers[MAX];
		Error errors[MAX]; 
	public:
		Status getStatus() const;
		void setStatus(Status status);
		void ValidateEmail();
		void ValidatePassword();
		void ValidateUser();
		void setUser(Details user);
		void createUser(Details user);
		void allErrors();
		
};
#endif
