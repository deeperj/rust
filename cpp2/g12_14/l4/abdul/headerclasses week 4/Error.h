#pragma once
#include <iostream> 
using namespace std;
#include <string>
class Error
{
private:
	int code;
	string message;
public:
	int getError();
	void setError(int code);
	string getMessage();
	void setMessage(std::string message);
};
