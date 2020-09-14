#pragma once

#include <vector>
#include <string>
#include "Details.h"
#include "Error.h"
#include "Status.h"
using namespace std;

class Session
{
private:
	Details user;
	Status status;
	vector<Details> validUsers;
	vector<Error> errors;
public:
	Status getStatus();
	void setStatus(Status status);
	bool ValidateEmail(Details details);
	bool ValidatePassword(Details details);
	bool ValidateUser(Details details);
	void setUser(Details user);
	void createUser(Details user);
	vector<Error> Errors();
	void add(Error error);
};

