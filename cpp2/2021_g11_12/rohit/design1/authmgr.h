#ifndef AUTHMGR_H
#define AUTHMGR_H

#include <string>
#include <iostream>
#include <vector>
#include <assert.h>
// #include "point2d.h"
#include "curses.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Details
{
public:
    string PassordVerify;
    string Email;
    string Password;
    string EmailHash;
    void clear();
};

enum ErrorCode {UserNotFound,InvalidEmail,PasswordLengthError};
enum StatusCode {
    UserSession
    ,LoginSession
    ,LoginErrorSession
    ,RegisterErrorSession
    ,RegisterSession
};

class Error{
    ErrorCode code;
public:
    Error(ErrorCode);
    string message();
    void setError(ErrorCode);
    ErrorCode getError();
};

class Status{
    StatusCode code;
public:
    vector<Error> errors;
    void add(Error);
    string status();
    StatusCode statusCode();
    void setStatus(StatusCode);
};

class Utility
{
    void setHash(Details user){};
    void sendEmail(Details user){};
};
class Session
{
private:
    Status status;
    vector<Details> validUsers;
    bool ValidatePasswordLength();

public:
    friend class Test;
    Details user;
    Session();
    Status getStatus();
    void setStatus(StatusCode status);
    StatusCode getStatusCode();
    string toString();
    void ValidateEmail();
    void ValidatePassword();
    void ValidateUser();
};

class Manager
{
protected:
    Session session;
public:
    friend class Test;
    void Login();
    void Register();
    void RequestReset();
    void ResetPassword();
};

#endif