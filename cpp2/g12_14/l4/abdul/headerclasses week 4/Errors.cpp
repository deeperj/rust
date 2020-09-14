#include "Error.h"
int Error::getError()
{
	return code;
}

void Error::setError(int code)
{
	this->code = code;
}

std::string Error::getMessage()
{
	return message;
}

void Error::setMessage(std::string message)
{
	this->message = message;
}
