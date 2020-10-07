#pragma once
#include <iostream> 
using namespace std;
#include <string>

class Utility
{
public:
	string createHash(std::string message);
	void resetEmail(std::string message);
	bool checkHash(std::string message);
};

