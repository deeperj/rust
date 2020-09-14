#ifndef ERROR_H
#define ERROR_H
/* Header for the Error class (Error.h) */
#include <string>
using std::string;

 class Error {
private:
   int code;
  string message;
public:
   int getError() const;
   void setError(int code);
   string getMessage() const;
   void setMessage(string message);
};
#endif
