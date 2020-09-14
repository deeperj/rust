#include "Session.h"
Status Session::getStatus()
{
	return status;
}
void Session::setStatus(Status st)
{
	this->status = st;
}
bool Session::ValidateEmail(Details details)
{
	return true;
}
bool Session::ValidatePassword(Details details)
{
	return true;
}
bool Session::ValidateUser(Details details)
{
	return true;
}
void Session::setUser(Details usr)
{
	this->user = usr;
}
void Session::createUser(Details usr)
{
	this->user = usr;
}
std::vector<Error> Session::Errors()
{
	return errors;
}
void Session::add(Error err)
{
}