#ifndef ERRORH_H_INCLUDED
#define ERRORH_H_INCLUDED

// Header File included
#include<iostream>
#include<string.h>

using namespace std;

// class implementation
class Error
{
private:
	int code;
	char message[500];
public:
	int getError()
	{
	return(code);
	}

	void setError(int code1)
	{
	code=code1;
	}

	char* getMessage()
	{
	return(message);
	}

	void setMessage(char msg[])
	{
	  strcpy(message,msg);
	}
}; // end of Error class



#endif // ERRORH_H_INCLUDED
