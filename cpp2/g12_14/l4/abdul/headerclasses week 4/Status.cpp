#include "Status.h"
void Status::setStatus(int code)
{
	this->code = code;
}

void Status::setMessage(std::string message)
{
	this->message = message;
}

int Status::getStatus()
{
	return code;
}

std::string Status::getMessage()
{
	return message;
}

