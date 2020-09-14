#pragma once
#include <iostream> 
using namespace std;
#include <string>
class Details
{
public:
	string UserEmail;
	string UserPassword;
	string EmailHash;
	Details(const Details& d);
};
