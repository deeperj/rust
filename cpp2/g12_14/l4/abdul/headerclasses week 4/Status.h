#pragma once
#include <iostream> 
using namespace std;
#include <string>
class Status
{
private:
	int code;
	string message;
public:
	void setStatus(int code);
	void setMessage(std::string message);
	int getStatus();
	string getMessage();
}; 


