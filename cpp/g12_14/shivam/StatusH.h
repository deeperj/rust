#ifndef STATUSH_H_INCLUDED
#define STATUSH_H_INCLUDED

// Header File included
#include<iostream>
#include<string.h>

using namespace std;


// class implementation
class Status
{
private:
	int code;
	char message[100];
public:
	void setStatus(int code1)
	{
	code=code1;
	}

	void setMessage(char status[])
	{
	strcpy(message,status);
	}

	int getStatus()
	{
	return(code);
	}

	char* getMessage()
	{
	 return(message);
	}
}; // end of Status class



#endif // STATUSH_H_INCLUDED
