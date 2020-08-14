/* Header for the Status class (Status.h) */
#ifndef STATUS_H
#define STATUS_H
#include <string>   // using string
using namespace std;
class Status{
	  private:
	  int code;
  	string message;	
	public:
	 int getStatus() const;
  	 void setStatus(int code);
   	 string getMessage() const;
     void setMessage(string message);
}; 
#endif
